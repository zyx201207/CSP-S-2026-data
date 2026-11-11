#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10;

ll n,m,ans,p;
ll a[N],b[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        b[i-1]=a[i]-a[i-1];
    }

    for(int i=1;i<n;i++){
        ll sum=0;
        p=m;

        for(int j=1;j>=0;j--){
            ll a1=a[i]-a[j];
            if(p<a1){
                p-=a1;
                sum++;
            }
        }

        if(i==n-1){
            for(int j=0;j<n-1;j++){
                if(p-a[i]-a[i-j-1]<0){
                    break;
                }
                p-=(a[i]-a[i-j-1]);
                sum++;
            }
        }

        int jian=i-1,jia=i+1;
        for(int j=0;j<n-1;j++){
            int a1=min(a[i]-a[i-1],a[i+1]-a[i]);
            if(p<a1){
                break;
            }else{
                sum++;
                p-=a1;
            if(a1=a[i]-a[i-1] && i==1){
                        if(n==i+2){
                            break;
                            jia++;
                        }else{
                            if(jia==n-1){
                                if(i==1){
                                    break;
                                }
                                jian--;
                            }
                        }
                    jia++;
                }
            }
        }
        ans=max(ans,sum);
    }

if(n>5000){
        ans=1; p=1;
        while(n>5000){
        if(m<p){
            break;
        }
        m-=p; p++; ans++;
    }
    cout<<ans;
    return 0;
}

if(n==1){cout<<1; return 0;}

if(ans>n){cout<<n; return 0;}

if(m==1 && n>=1){cout<<1; return 0;}
    cout<<ans;
    return 0;
}
