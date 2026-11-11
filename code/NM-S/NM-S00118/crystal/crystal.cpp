#include<bits/stdc++.h>
using namespace std;
unsigned long long m;
long long a[500005],cha[500005],n,cnt,p=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        cha[i]=a[i]-a[i-1];
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        unsigned long long d=0;int j=0;
        while(d<=m&&i+j<=n){
            d+=cha[i+j]*j;
            if(d>m){
                break;
            }
            j++;
        }
        if(j+i>n){
            if(i==1){
                p=1;
                if((m-d)%n==0){
                    cout<<n;break;
                }
                else {cout<<n-1;break;}
            }
        }
        if(j>maxx) maxx=j;
        }
    if(p==0) cout<<maxx;
    return 0;
}
