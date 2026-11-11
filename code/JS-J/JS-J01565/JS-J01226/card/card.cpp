#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],ans[100005];
stack <int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int t=1,b[1000005],flag=0;
            memset(b,0,sizeof(b));
            while (!s.empty()){
                b[t]=s.top();
                s.pop();
                if (b[t]==a[j]){
                    flag=1;
                    break;
                }
                t++;
            }
            if (flag)continue;
            for (int k=t;k>=1;k--){
                s.push(b[k]);
            }
            s.push(a[j]);
        }
        while (!s.empty()){
            int x=s.top();s.pop();
            ans[x]++;
        }
    }
    ans[1]++;
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
