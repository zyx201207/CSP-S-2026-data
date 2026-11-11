#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    if(n<=5){
        if(n==1){
            cout<<1;
        }
        if(n==2){
            if(a[2]-a[1]<=m){
                cout<<2;
            }
        }
        if(n==3){
            if(a[3]-a[2]+a[3]-a[1]<=m){
                cout<<3;
            }
            else if(a[3]-a[2]<=m||a[2]-a[1]<=m){
                cout<<2;
            }
            else cout<<1;
        }
        if(n==4){
            if(a[4]-a[3]+a[4]-a[2]+a[4]-a[1]<=m){
                cout<<4;
            }
            else if(a[4]-a[3]+a[4]-a[2]<=m||a[3]-a[2]+a[3]-a[1]<=m){
                cout<<3;
            }
            else if(a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m){
                cout<<2;
            }
            else cout<<1;
        }
        if(n==5){
            if(a[5]-a[4]+a[5]-a[3]+a[5]-a[2]+a[5]-a[1]<=m){
                cout<<5;
            }
            else if(a[5]-a[4]+a[5]-a[3]+a[5]-a[2]<=m||a[4]-a[3]+a[4]-a[2]+a[4]-a[1]<=m){
                cout<<4;
            }
            else if(a[5]-a[4]+a[5]-a[3]<=m||a[4]-a[3]+a[4]-a[2]<=m||a[3]-a[2]+a[2]-a[1]<=m){
                cout<<3;
            }
            else if(a[5]-a[4]<=m||a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m){
                cout<<2;
            }
            else cout<<1;
        }
    }
    long long ans=0,b=0,c=n;
    if(n>5){
        for(int i=1;i<=n;i++){
            if(a[i]==i){
                ans++;
            }
        }
        if(ans>=n-1){
            for(int i=n;i>=1;i--){
                if(i*(i-1)/2<=m){
                    cout<<i;
                    return 0;
                }
            }
        }
        if(ans<n){
            b=a[2]-a[1];

            for(int i=a[n];i>=1;i-=b){
                if(i*(i-b)/(2*b)<=m){
                    cout<<c;

                    return 0;
                }

                else c--;
            }
        }

    }

    return 0;
}
