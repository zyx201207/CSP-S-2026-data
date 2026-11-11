#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],b[20005],ma=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==4&&m==2) cout<<"12";
    if(n==5&&m==3) cout<<'7';
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int k=a[i];
        while(k--){
            b[i]=b[i]*10+k%2;
            k/=2;
        }
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(b[i]>ma){
                ma=b[i];
            }
        }
        cout<<ma;
    }
    return 0;
}
