def Fractional_Knapsack(weight,value,Total):
    dict1={}
    v=0
    for i in range(len(weight)):
        a=value[i]
        b=weight[i]
        dict1[a/b]=[a,b]
    for i in reversed(sorted(dict1.keys())):
        if dict1[i][1]<=Total:
            Total-=dict1[i][1]
            v+=dict1[i][0]
        else:
            v+=i*Total
            Total=0
            return v
N=int(input('Number of items:'))
value=[]
weight=[]
for i in range(N):
    value.append(int(input('Value:')))
    weight.append(int(input('Weight:')))
Total=int(input('Total capacity of Knapsack:'))
print(round(Fractional_Knapsack(weight,value,Total)))
