#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    deque<int> q;
    vector<bool> mark(m+1,false);
    vector<int> ans(m+1);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(mark[a[j]]){
                while(q.back()!=a[j]) {
                    int last=q.back();
                    q.pop_back();
                    mark[last]=false;
                }
            }else{
                q.push_back(a[j]);
                mark[a[j]]=true;
            }
        }

        while(!q.empty()){
            ans[q.front()]++;
            mark[q.front()]=false;
            q.pop_front();
        }
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
