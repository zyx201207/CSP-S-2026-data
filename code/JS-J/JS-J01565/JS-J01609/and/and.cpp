#include<bits/stdc++.h>
using namespace std;
int n,m,ma,ans,sum,l,a[500001],c[500001],s[500001];
int checkbinbit(int x){
    int returned=0;
    while(x>0){
        x/=2;
        returned++;
    }
    return returned;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    ma=checkbinbit(ma)-1;
    for(int i=ma;i>=0;i--){
        sum=0,l=0;
        for(int j=1;j<=n;j++){
            if((a[j]&(1<<i))==(1<<i)){
                sum++;
                c[++l]=a[j];
                //cout<<c[l]<<' ';
            }
        }
        //cout<<"\n";
        if(sum>=m){
            for(int j=1;j<=l;j++){
                a[j]=c[j];
            }
            n=l;
            ans+=(1<<i);
            //cout<<ans<<' '<<(1<<i)<<"\n";
        }
    }
    cout<<ans;
}
