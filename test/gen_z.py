import random

for day in range(0,35):
    print("\n\n- JOUR :",day," -")
    for i in range (0,15):
        z = 0
        kilometer = random.randint(0,20)
        if i < 12:
            z = ((random.randint(0,14)+day*3)/5) - random.randint(0,7) + random.randint(0,int(kilometer/7+1)) - random.randint(0,3)
            if (z<0):
                z=0
            print("  ",i,"DESERT :",int(z))
        else:
            z = ((random.randint(0,14)+day*3)/5) - random.randint(0,6) + random.randint(0,int(kilometer/5+1)) - random.randint(0,2)
            if (z<5):
                z=0
            print("  ",i,"BATIME :",int(z))
        

input()