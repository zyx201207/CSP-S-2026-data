/*
bad in j
should be nice in s?
*/
/*
bad s
t1 wei he bu guo da yang li
0pts
i have no idea
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<long long>d(n);
    for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
    d[0]=a[0];
    unsigned long long sum=0,res=0,r2=1;
    for(int i=0,j=0;i<n-1&&j<n-1;){
        if(sum+d[j]<=m)sum+=d[j++],r2++;
        else{
            sum=0;
            j++,i=j;
            res=max(res,r2);
            r2=1;
        }
    }
    cout<<max(r2,res)<<'\n';
}