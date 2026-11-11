#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[500005]={0};
int b[500005]={0};
int l=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)
            bool flag=false;
            int sum=l;
            for(int k=0;k<sum;k++){
                if(b[k]==j){
                    flag=true;
                }
                if(flag){
                    b[k]=0;
                    l--;
                }
            }
            b[l]=j;
        }
        for(int j=0;j<l;j++){
            if(b[j]==i){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
