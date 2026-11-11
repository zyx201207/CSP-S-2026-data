#include <bits/stdc++.h>

using namespace std;

long long n,m,a[5000100],maxn=0,c[5000010],ans=0,flag1,flag2;
void check1(long long x){
    long long t=1,cnt=1;
    while(x>=cnt&&t<=n){
        ans++;
        t++;
        cnt+=t;
    }
    cout<<ans+1;
}
void check2(long long x){
    long long t=0,cnt=0,step=0;
    while(m>=cnt&&step<n){
        ans++;
        step++;
        t+=x;
        cnt+=t;
    }
    cout<<ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i)
        {
            flag1++;
        }
    }
    if(flag1==n)
    {
        check1(m);
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
        if(c[i]==c[i-1]) flag2++;
    }
    if(flag2==n-2){
        check2(c[1]);
        return 0;
    }
    long long l=1;
    long long r=n;
    ans=n;
    while(l<=r){
        long long cnt=0;
        for(long long i=l;i<=r-1;i++){
            cnt+=c[i]*(i-l+1);
        }
        if(cnt>m){
            ans--;
            if(c[l]>c[r-1])
                l++;
            else r--;
        }
        else break;
    }
    cout<<ans;
    return 0;
}
