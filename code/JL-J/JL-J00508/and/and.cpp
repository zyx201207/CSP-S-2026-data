#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],ma=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++)
            if(ma<a[i])
                ma=a[i];
        cout<<ma;
        return 0;
    }
    if(m==2){
        for(long long i=1;i<n;i++)
            for(long long j=i+1;j<=n;j++)
                if(ma<(a[i]&a[j]))
                    ma=a[i]&a[j];
        cout<<ma;
        return 0;
    }
    if(m==3){
        for(long long i=1;i<=n-2;i++)
            for(long long j=i+1;j<=n-1;j++)
                for(long long x=j+1;x<=n;x++)
                    if(ma<(a[i]&a[j]&a[x]))
                        ma=(a[i]&a[j]&a[x]);
        cout<<ma;
        return 0;
    }
    if(n<=2000&&m==n){
            ma=a[1];
        for(int i=2;i<=n;i++){
            ma=a[i]*ma;
        }

    }
    return 0;
}
