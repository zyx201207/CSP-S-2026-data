#include<bits/stdc++.h>
using namespace std;
const int N=200000+5;
int a[N],no[N],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=30;i>=0;i--){
        int ci=0;
        for(int j=1;j<=n;j++){
            if(no[j]==0)ci+=(a[j]>>i)%2;
        }
        if(ci>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if((a[j]>>i)%2==0){
                    no[j]=1;
                }
            }
        }
    }
    cout<<ans;
}
//finish at 9:39