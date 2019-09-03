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
1 1 1 1 1 1 1 1 1 1
"""

vWall = """
1 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 0 0 0 1
"""


def getWorld(world):
    height = len(world.strip().split('\n'))
    width = len(world.strip().split('\n')[0].split(' '))

    world = world.strip().split('\n')


    nworld = []
    for i in range(height):
        nworld.append([1])

    for x in range(height):
        for y in range(width):
            nworld[x].append(int(world[x].strip().split()[y]))

    return nworld


def printWorld(world):
    for row in world:
        rowp = ''
        for cell in row:
            rowp+=str(cell)+' '

        print(rowp.strip())

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
def floodFill(world, hWall, vWall):
    x = 2
    y = 2

    worldWidth = len(world)
    worldHeight = len(world[0])

    theStack = [(x + 1, y + 1, 0), (x + 1, y, 0), (x, y + 1, 0), (x, y, 0)]
    while len(theStack) > 0:

        x, y, val = theStack.pop()
        # print(theStack)

        # print(val)
        if world[y][x] < val:
            # print('continued')
            continue

        world[y][x] = val

        if vWall[y][x] != 1:  # left
            # print('left')
            theStack.append((x - 1, y, val + 1))

        if hWall[y][x] != 1:  # up
            theStack.append((x, y - 1, val + 1))
            # print('up')

        if vWall[y][x + 1] != 1:  # right
            theStack.append((x + 1, y, val + 1))
            # print('right')

        if hWall[y + 1][x] != 1:  # down
            theStack.append((x, y + 1, val + 1))
            # print('down')

# world = getWorld(map)
# printWorld(world)
# traverse(world, hWall, world)
# print(len(world[0]))

# hWall = getWorld(hWall)
# printWorld
# print(hWall)
# vWall = getWorld(vWall)
# printWorld(vWall)
# print(vWall)


world=[[100,100,100,100,100,100],
       [100,100,100,100,100,100],
       [100,100,100,100,100,100],
       [100,100,100,100,100,100],
       [100,100,100,100,100,100],
       [100,100,100,100,100,100]]

hWall = [[1,1,1,1,1,1],
         [1,1,1,1,1,0],
         [0,0,0,0,0,0],
         [0,0,0,0,0,0],
         [0,0,0,0,0,0],
         [0,0,0,0,0,0],
         [1,1,1,1,1,1]]

vWall = [[1,0,0,0,0,0,1],
         [1,0,0,0,0,0,1],
         [1,0,0,0,0,0,1],
         [1,0,0,0,0,0,1],
         [1,0,0,0,0,0,1],
         [1,0,0,0,0,0,1]]


floodFill(world, hWall, vWall)
printWorld(world)