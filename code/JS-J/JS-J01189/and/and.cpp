#include<bits/stdc++.h>

using namespace std;
int n,m,ans;
vector<int>v,vt;
void f(int c,int p){

    if(c==m){
        int ands=vt[0];
        for(int i=1;i<vt.size();i++){
            ands&=vt[i];
        }
        ans=max(ans,ands);
        return;
    }
    for(int i=p;i<=n-m+c;i++){
        vt.push_back(v[i]);
        f(c+1,i+1);
        vt.pop_back();
    }
}

int main(){
    ifstream cin("and.in");
    ofstream cout("and.out");
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    f(0,0);
    cout<<ans;
    return 0;
}
