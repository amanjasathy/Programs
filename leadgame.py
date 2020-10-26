n=int(input())
e=[]
f=[]
for i in range(0,n):
    a,b=map(int,input().split( ))
    c=a-b
    d=b-a
    if c>d :
        e.append(c)
    else:
        f.append(d)
if(len(e)>len(f)):
    print(1,max(e))
else:
    print(2,max(f))
        
