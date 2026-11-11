#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int b[500005];
bool f[300005];
stack<int> q;
//final
int main () {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
            while (!q.empty()) {
                q.pop();
            }
            memset(f,false,sizeof(f));
        for (int j=i;j<=n;j++) {
                //cout<<a[j]<<" ";
            while (f[a[j]]==true) {
                int t=q.top();
                f[t]=false;
                q.pop();
            }
            int k=a[j];
            q.push(a[j]);
            f[k]=true;
        }//cout<<endl;
        while (!q.empty()) {
            int num=q.top();
        //cout<<num<<" ";
            cnt[num]++;
            q.pop();
        }
    }

    for (int i=1;i<=m;i++) {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
