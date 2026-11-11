#include<bits/stdc++.h>
using namespace std;
int a[500010],suf[500010][3],cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for (int i = 1;i<=n;i++)cin>>a[i];
    if (m==2){

        for (int i = n;i>=1;i--){
            suf[i][1]=suf[i+1][1];
            suf[i][2]=suf[i+1][2];
            if (a[i]==1)suf[i][1]++;
            else suf[i][2]++;
        }
        int p=0,q=0;
        for (int i = 1;i<=n;i++){
            if (suf[i][1]%2==1)p++;
            if (suf[i][2]%2==2)q++;
        }
        cout << p << ' ' << q;
        return 0;
    }
    /*for (int i = 1;i<=n;i++){
        queue<int>q;

        for (int j = i;j<=n;j++){
            bool f=1;
            for (auto v :q){
                if (v==a[j]){
                    f=0;
                }if (f=0)q.pop();
            }
            if (f)q.push(a[j]);
        }
        for (int j = 1;j<=m;j++){
            for (auto v : q){
                if (v==j){
                    cnt[m]++;
                    break;
                }
            }
        }
    }
    for (int i = 1;i<=m;i++)cout << cnt[i];*/
    return 0;
}
