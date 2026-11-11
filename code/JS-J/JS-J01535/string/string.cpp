#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    long long l=1,r=n,ls=a[1],rs=a[n];
    char lz=b[1],rz=b[n];
    while(l<r)
    {
        lz=b[l];
        rz=b[r];
        if(lz!=rz){
            if(ls<rs){
                ans+=ls;
                rs-=ls;
                l++;
                ls=a[l];
            }
            else if(rs<ls){
                ans+=rs;
                ls-=rs;
                r--;
                rs=a[r];
            }
            else if(rs==ls)
            {
                ans+=rs;
                r--;
                l++;
                ls=a[l];
                rs=a[r];
            }
        }
        else{
            if(ls<rs){
                rs-=ls;
                l++;
                ls=a[l];
            }
            else if(rs<ls){
                ls-=rs;
                r--;
                rs=a[r];
            }
            else if(rs==ls)
            {
                r--;
                l++;
                ls=a[l];
                rs=a[r];
            }
        }
        if(l>r) break;
    }
    cout<<ans;
    return 0;
}