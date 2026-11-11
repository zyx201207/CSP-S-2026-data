#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
const int M=3*1e5+5;
int n,m,a[N];
map<int,int> ans;
//wo tm bu hui xue zhan, yao bu ran 50 fen le ToT, zhe bu hui le ma? t2 hai mei AC.
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        stack<int> q;
        bool f[N]={false};
        for(int j=i;j<n;++j){
            if(f[a[j]]){
                while(q.top()!=a[j]){
                    f[q.top()]=false;
                    q.pop();
                }
                q.pop();
                q.push(a[j]);
            }else{
                f[a[j]]=true;
                q.push(a[j]);
            }
        }
        while(!q.empty()){
            ++ans[q.top()];
            q.pop();
        }
    }
    for(auto i:ans) cout<<i.second<<" ";
}
