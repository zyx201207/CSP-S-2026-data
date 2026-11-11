#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    deque<int> q;
    long long ans=0,all=0;
    for(auto i:v){
        if(!q.empty())all+=(i-q.back())*q.size();
        else all=0;
        q.push_back(i);
        while(all>m){
            all-=q.back()-q.front();
            q.pop_front();
        }
        ans=max(ans,(long long)q.size());
    }
    cout<<ans<<endl;
    return 0;
}