a=input()
b=input()
a=a.split(" ")
b=b.split(" ")
print(a)
print(b)
num_road=int(a[1])
num_vication=int(a[4])
road=list()
for i in range(0,num_road):
    temp=input()
    temp=temp.split(" ")
    for j in range(0,len(temp)):
        road.append(int(temp[j]))
    road.append("s")
vication=list()
for i in range(0,num_vication):
    temp = input()
    temp = temp.split(" ")
    for j in range(0, len(temp)):
        vication.append(int(temp[j]))
    vication.append("s")






time_use=0
for i in range(0,num_vication):
    k=0
    time_use=0
    print(vication[vication.index("s",3*k,3*k+2)])
