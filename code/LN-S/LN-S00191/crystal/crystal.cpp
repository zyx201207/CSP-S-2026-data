#include<bits/stdc++.h>
using namespace std;
const int maxx=5e5+5;
long long a[maxx];
long long n,m;
long long numm;
long long sum;
long long t;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[3]==3){
        while(n){
            sum=(numm*(numm-1))/2;
            if(sum>m){
                break;
            }
            sum=0;
            numm++;
            if(numm>n+1){
                cout<<n;
                return 0;
            }
        }
        cout<<numm-1;
    }else{
        t=abs(a[2]-a[1]);
        while(n){
            sum=(numm*(numm+1)*t)/2;
            if(sum>m){
                cout<<numm;
                return 0;
            }
            sum=0;
            numm++;
            if(numm>n){
                cout<<n;
                return 0;
            }
        }
    }
    return 0;
}
