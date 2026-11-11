#include<bits/stdc++.h>
std::ifstream fin("and.in");
std::ofstream fout("and.out");
int a[200001];
int main(){
    int n,m;
    fin>>n>>m;
    int ans=0;
    std::priority_queue<int> q;
    for(int i=0;i<n;++i){
        fin>>a[i];
        q.push(a[i]);
    }
    for(int i=0;i<m;++i){
        ans=q.top();
        q.pop();
    }
    fout<<ans;
}
