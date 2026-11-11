#include <bits/stdc++.h>
using namespace std;
int num[300015],ans[300015];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500015];
    cin>>n>>m;
    int ca[500015]={0},right=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)num[j]=0;
        for(int j=1;j<=n;j++)ca[j]=0;
        for(int j=i;j<=n;j++){
            if(num[a[i]]==0){
                ca[right++]=a[i];
                num[a[i]]=1;
            }
            else{
                bool flag=1;
                for(int k=1;k<=right;k++){
                    if(flag==0){
                        ca[k]=0;
                        num[ca[k]]=0;
                    }
                    if(flag==1&&ca[k]==a[i]){
                        right=k;
                        flag=0;
                        ca[k]=0;
                    }
                }
                ca[right]=a[i];
            }
        }
        for(int i=1;i<=m;i++){
            if(num[i]==1){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
