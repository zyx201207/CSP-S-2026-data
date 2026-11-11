#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,s[200005][2],tmp=1,mid,a,b,c,d,rmid,cnt;
char l,r,t[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        int x;
        cin>>x>>t[i];
        s[i][0]=tmp;
        tmp+=x;
        s[i][1]=tmp-1;
    }
    tmp--;
    mid=tmp/2;
    rmid=mid;
    if(tmp%2==1)
        rmid++;
    l=t[1],r=t[n],a=s[1][1],b=s[n][0],c=1,d=n;
    for(int i=1;i<=mid;i++)
    {
        if(i>a)
        {
            c++;
            l=t[c];
            a=s[c][1];
        }
        if(i+rmid<b)
        {
            d--;
            r=t[d];
            b=s[d][0];
        }
        if(l!=r)
            cnt++;
    }
    cout<<cnt;
    return 0;
}