#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q[300005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    for(int i=1;i<=n;++i){
        stack<int> g;
        int f[300005]={0};
        for(int j=i;j<=n;++j){
            if(f[a[j]]==0){
                g.push(a[j]);
                f[a[j]]=1;
            }
            else{
                while(!g.empty()&&g.top()!=a[j]){
                    f[g.top()]=0;
                    g.pop();
                }
            }
        }
        while(!g.empty()){
            q[g.top()]++;
            g.pop();
        }
    }
    for(int i=1;i<=m;++i){
        cout << q[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
}
