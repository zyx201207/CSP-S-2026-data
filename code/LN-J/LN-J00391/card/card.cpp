#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010];
int zhizhen;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b[500010]={};
    for(int k=1;k<=n;k++){
        zhizhen=k;
        for(int i=1;i<=n;i++){
            b[i]=a[i];
        }
        int tong[300010]={};
        for(int i=k;i<=n;i++){
            if(tong[b[i]]==0){
                tong[b[i]]=1;
            }else{
                int flag=1,flag1;
                for(int j=i-1;;j--){
                    if(b[i]==b[j]){
                        flag1=j-1;
                        break;
                    }
                    tong[b[j]]=0;
                    flag++;
                }
                for(int j=zhizhen;j<=flag1;j++){
                    b[j+flag]=b[j];
                    b[j]=0;
                }
                zhizhen+=flag;
            }
        }
        for(int i=zhizhen;i<=n;i++){
                ans[b[i]]++;
            }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
