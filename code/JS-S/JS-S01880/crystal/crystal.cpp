#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
long long a[maxn];
long long dt[maxn],qd[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    int flaga=1,flagb=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)flaga=0;
    }
    long long d=a[2]-a[1];
    for(int i=1;i<=n-1;i++){
        if(a[i+1]-a[i]!=d)flagb=0;
    }
    if(flaga){
        int cnt=1;
        for(int i=1;i<=n;i++){
            m-=(long long)i;
            if(m<0)break;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    else if(flagb){
        int cnt=1;
        d=abs(d);
        for(int i=1;i<=n;i++){
            m-=((long long)i)*d;
            if(m<0)break;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    else{
        int cnt=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            dt[i]=a[i]-a[1];
        }
        for(int i=1;i<=n;i++){
            qd[i]=qd[i-1]+dt[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long k= (long long)j-i+1;
                long long dss= k*dt[j]-qd[j]+qd[i-1];
                if(m>=dss){
                    cnt=max(cnt,j-i+1);
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
