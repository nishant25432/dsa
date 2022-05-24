A = []
B = []
C = []
D = []
def add():

    n = int(input("Enter the number of elements to be added in set A:"))
    for i in range(n):
        element = int(input("enter the element:"))
        A.append(element)
    print(A)


    m = int(input("enter the number of elements to be added in set B:"))
    for i in range(m):
        element = int(input("enter the element:"))
        B.append(element)
    print(B)


def remove():
    x = int(input("enter the element to be removed from A:"))
    if (x in A):
        A.remove(x)
    print(A)

    y = int(input("enter the element to be removed from B:"))
    if (y in B):
        B.remove(y)
    print(B)

def intersection():
    for i in A:
        if i in B:
            C.append(i)
    print(C)

def union():
    for i in A:
        D.append(i)
    for i in B:
        if i not in A:
            D.append(i)
    print(D)

print("MENU")
print("1.add")
print("2.remove")
print("3.intersection")
print("4.union")

while(True):
    ch=int(input("enter any option from menu:"))
    if(ch==1):
        add();
    elif(ch==2):
        remove();
    elif(ch==3):
        intersection();
    elif(ch==4):
        union();
    else:
        break;
