#include <bits/stdc++.h> 
using namespace std; 
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    vector<int> a,b;
    int n,val,c1=0,c2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        a.push_back(val);
    }
    for(int i=0;i<n;i++)
    {
        cin>>val;
        b.push_back(val);
    }
    int ele;
    vector<int> tv;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[b[j]].push_back(gcd(a[i],b[j]));
            if(mp[b[j]][i]!=1 && a[i]<b[j])
            {
                c1+=1;

            }
        }
    }
    int i=0,j;
    for(auto x:mp)
    {
        int ele=x.first;
        vector<int> tv=x.second;
        for(j=0;j<tv.size();j++)
        {
            if(tv[j]!=1 && b[i]<a[j])
                c2+=1;
        }
        i+=1;
    }
    cout<<max(c1,c2)<<endl;
}
