#include<bits/stdc++.h>
using namespace std;
int a[5010],c[3010],ans[5010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        memset(c,-1,sizeof(c));
        stack<int> v;
        for(int j=i;j<=n;j++){
            if(c[a[j]] == -1){
                v.push(a[j]);
                int len = v.size();
                c[a[j]] = len;
            }
            else{
                for(int k=c[a[j]];k<v.size();k++){
                    c[v.top()] = -1;
                    v.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(c[j] != -1){
                ans[j] ++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
