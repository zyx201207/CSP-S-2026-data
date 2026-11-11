#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N],now[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        memset(now,-1,sizeof(now));
        v.clear();
        for(int j=i;j<=n;j++){
            if(now[a[j]]!=-1){
                for(int x=now[a[j]]-1;x<=v.size();x++){
                        v.pop_back();
                }
            }
            v.push_back(a[j]);
            now[a[j]]=v.size();
        }
       for(int s=0;s<v.size();s++) cout<<v[s]<<" ";
       cout<<endl<<endl;
        for(int y=0;y<v.size();y++) ans[v[y]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
