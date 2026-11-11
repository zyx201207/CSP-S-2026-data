#include<bits/stdc++.h>
using namespace std;
long long n,m,a1[5*int(1e5)+5],a2[5*int(1e5)+5],ans[3*int(1e5)+5]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a1[i];
        a2[i]=a1[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a2[j]=a1[j];

        for(int j=i;j<=n;j++){
            bool flag=false;
            for(int l=i;l<j;l++){
                if(a2[l]==a2[j]) flag=true;
                if(flag) a2[l]=0;
            }
        }

        for(int j=i;j<=n;j++){
            if(a2[j]==0) continue;

            ans[a2[j]]++;
        }
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
