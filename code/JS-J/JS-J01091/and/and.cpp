#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5*2+5;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    ll maxa1=0,maxa2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa1=max(maxa1,a[i]);

    }
    if(m==n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i]&a[i+1];
        }
        cout<<sum;
        return 0;
    }
    if(m==1){
       cout<<maxa1;
       return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j){
                    ll x=a[i]&a[j];
                    maxa2=max(maxa2,x);
                }
            }
        }
        cout<<maxa2;
        return 0;
    }
    return 0;
}
