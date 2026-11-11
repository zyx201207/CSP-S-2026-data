#include<bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &a,const int &i_){
    vector<int> ans_;
    //int ans=0;
    int n=a.size();
    for(int i=i_;i<n;i++){
        auto it=find(ans_.begin(),ans_.end(),a[i]);
        if(it!=ans_.end()){
            vector<int> temp(ans_.begin(),it);
            ans_=temp;
            ans_.push_back(a[i]);
        }else{
            ans_.push_back(a[i]);
            //map_[a[i]]=1;
        }
    }
    return ans_;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> vis(m);
    vector<int> temp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        temp=f(a,i);
        for(int &j:temp){
            vis[j]++;
        }
        //cout<<'\n';
    }

    for(int i=1;i<=m;i++){
        cout<<vis[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
