#include<bits/stdc++.h>
using namespace std;
int a[200005],s[300005],cnt = 0,ans[300005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            t[j] = 0;
            s[j] = 0;
        }
        cnt = 0;
        for(int j = i;j<=n;j++){
            if(s[a[j]]){
                while(1){
                    cnt--;
                    if(t[cnt] == a[j])break;
                }
                t[cnt] = a[j];
            }else{
                s[a[j]]++;
                t[++cnt] = a[j];
            }
        }
        for(int k = 1;k<=cnt;k++)ans[t[k]]++;
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
