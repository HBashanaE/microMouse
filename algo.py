map = """
8 7 6 5 4 4 4 6 7 8
7 6 5 4 3 3 3 5 6 7
6 5 4 3 2 2 2 4 5 6
5 4 3 2 1 1 1 3 4 5
4 3 2 1 0 0 1 2 3 4
4 3 2 1 0 0 1 2 3 4
5 4 3 2 1 1 2 3 4 5
6 5 4 3 2 2 3 4 5 6
7 6 5 4 3 3 0 5 6 7
8 7 6 5 4 4 5 6 7 8
"""
hWall = """
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
"""

vWall = """
1 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 0 1
"""


def getWorld(map):
    height = len(map.strip().split('\n'))
    width = len(map.strip().split('\n')[0].split(' '))

    map = map.strip().split('\n')

    world = []
    for i in range(height):
        world.append([' '])

    print(len(world))
    for x in range(height):
        world[x] = map[x].strip().split()

    return world


def printWorld(world):
    for row in world:
        print(" ".join(row))


def floodFill(world, hWall, vWall):
    x = 4
    y = 4

    worldWidth = len(world)
    worldHeight = len(world[0])

    for i in range(worldHeight):
        world[i] = ['-', '-', '-', '-', '-', '-', '-', '-', '-', '-']

    oldChar = '-'

    theStack = [(x + 1, y + x, 0), (x + 1, y, 0), (x, y + 1, 0), (x, y, 0)]
    count = 1
    while len(theStack) > 0:

        x, y, val = theStack.pop()

        if world[x][y] != '-':
            # Base case. If the current x, y character is not the oldChar,
            # then do nothing.
            continue
        # SS += 1

        # Change the character at world[x][y] to newChar
        world[x][y] = val

        if vWall[x][y] != 1:  # left
            theStack.append((x - 1, y, count))

        if hWall[x][y] != 1:  # up
            theStack.append((x, y - 1, count))

        if vWall[x + 1][y] != 1:  # right
            theStack.append((x + 1, y, count))

        if hWall[x][y + 1] != 1:  # down
            theStack.append((x, y + 1, count))

        count += 1



def traverse(map, hWall, vWall):
    dir = 1

    x, y = (0, 0)
    next_x, next_y = (0, 0)

    while True:
        turn = dir
        if (y != 0 and map[x][y - 1] < map[x][y]):
            turn = 4
            next_x, next_y = (x, y - 1)
            # print('a')
        if (x != 0 and map[x - 1][y] < map[x][y]):
            turn = 3
            next_x, next_y = (x - 1, y)
            # print('b')
        if (y != 10 and map[x][y + 1] < map[x][y]):
            turn = 2
            next_x, next_y = (x, y + 1)
            # print('c')
        if (x != 10 and map[x + 1][y] < map[x][y]):
            turn = 1
            next_x, next_y = (x + 1, y)
            # print('d')

        if (dir - turn == 0):
            print('No turn')
        if (dir - turn == -1):
            print('Turn right')
            dir += 1
            dir %= 4
        if (dir - turn == 1):
            print('Turn left')
            dir -= 1
            dir %= 4
        if (dir - turn == -2):
            print('Turn around')
        if (dir - turn == 2):
            print('Turn around')
        if (dir - turn == -3):
            print('Turn left')
            dir -= 1
            dir %= 4
        if (dir - turn == 3):
            print('Turn right')
            dir += 1
            dir %= 4

        x, y = (next_x, next_y)
        print(next_x, next_y)
        print(map[x][y])

        if (map[x][y] == '0'):
            print('end')
            break


world = getWorld(map)
# printWorld(world)
# traverse(world, hWall, world)
# print(len(world[0]))

hWall = getWorld(hWall)
printWorld(hWall)
vWall = getWorld(vWall)

floodFill(world, hWall, world)
