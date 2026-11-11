#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],desk[300005],top,ans[300005];
bool chm[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        top=0;
        for(int i=0;i<=m;i++){
            chm[i]=0;
        }
        for(int j=i;j<=n;j++){
            if(chm[a[j]]){
                while(1){
                    chm[top]=0;
                    if(desk[top]==a[j]){
                        top--;
                        break;
                    }
                    top--;
                }
            }
            desk[++top]=a[j];
            chm[desk[top]]=1;
        }
        for(int i=1;i<=top;i++){
            ans[desk[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
