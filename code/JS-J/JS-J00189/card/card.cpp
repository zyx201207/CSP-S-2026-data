#include<bits/stdc++.h>
using namespace std;
int n,m,f[300005],num[300005],a[500005];
stack<int>q;
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
        for(int j=i;j<=n;j++){

            if(f[a[j]]==0){
                q.push(a[j]);
            }

            else{
                while(q.top()!=a[j]){
                    f[q.top()]=0;
                    q.pop();
                }

            }
            f[a[j]]=j;
        }
        while(q.size()){
            num[q.top()]++;
            f[q.top()]=0;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
/*freopen
()/[]/{}
return 0
quanju/jubu
endl->\n
int->ll
*/
