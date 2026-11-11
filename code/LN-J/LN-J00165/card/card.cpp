#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        for(int j=1;j<=n;j++){
            b[j]=a[j];
        }
        stack<int> d;
        for(int j=i;j<=n;j++){
            if(c[b[j]]==0){
                d.push(b[j]);
                c[b[j]]++;
            }
            else{
                while(1){
                    if(d.top()==b[j]){
                        break;
                    }
                    c[d.top()]--;
                    d.pop();
                }
            }
        }
        memset(c,0,sizeof(c));
        while(!d.empty()){
            if(d.top()>0&&d.top()<=m&&c[d.top()]==0){
                ans[d.top()]++;
                c[d.top()]=1;
            }
            d.pop();
        }
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}
