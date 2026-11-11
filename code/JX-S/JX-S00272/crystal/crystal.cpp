#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int k=0;k<=n;k++){
        for(int j=m;j>=0;j--){
            if(a[k]+=1==a[k+1]&&j==0){
                    ans+=1;
                    a[k]+=1;

        }
        break;
        }

    }



    cout<<ans;
    return 0;
}
