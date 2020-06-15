from collections import Counter as c
n,t=map(int,input().split())
li=[]
ans=''
for i in range(n):
    li.append(input())
for i in range(t):
    lo=[]
    for j in li:
        lo.append(j[i])
    co=c(lo)
    k=max(co.values())
    op=chr(133)
    for j in co.keys():
        if co[j]==k:
            op=min(j,op)
    ans+=op
print(ans)
