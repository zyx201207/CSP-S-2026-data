#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long c1;
long long k,j,mans;
long long num[500001];
bool comp(long long a,long long b)
{
    return a<b;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>c1;
        num[i]=c1;
    }
    sort(num,num+n,comp);
    mans=-100;
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1)
        {
            k-=((i-j)*(num[i+1]-num[i]));
        }
        else
        {
            k=0;
            j=i;
        }
        while(k<=m)
        {
            k+=num[i]-num[j];
            j--;
            if(j<0) break;
        }
        mans=max(mans,i-j);
        if(j<-1) break;
    }
    cout<<mans;
    return 0;
}