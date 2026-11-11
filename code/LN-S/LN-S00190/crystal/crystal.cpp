#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans=0;
long long ch=0,la=0;
bool f=true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1]>>a[2];
    la=a[2]-a[1];
    for(int i=3;i<=n;i++){
        cin>>a[i];
        ch=a[i]-a[i-1];
        if(ch!=la){
            f=false;
        }
        la=ch;
    }
    if(f){
        long long use=0;
        for(long long i=1;i<=n;i++){
            use+=la*i;
            if(use>m){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        long long rest=m;
        long long num=1;
        for(long long j=i-1;j>0;j--){
            rest-=a[i]-a[j];
            if(rest>=0) num++;
            else break;
        }
        ans=max(ans,num);
    }
    cout<<ans;
    return 0;
}
