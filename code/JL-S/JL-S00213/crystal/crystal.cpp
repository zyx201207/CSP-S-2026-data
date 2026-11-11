#include<bits/stdc++.h>
using namespace std;
const int N=10000010;
int a[N];
vector<int> k;
int ck(int n){
    int ma=-1e9;
    for(int i=0;i<n;i++){
        int p=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]) p++;
        }
        if(ma<p) ma=p;
    }
    return ma;
}
void dfs(int n,int m){
    if(m==0){
        k.push_back(ck(n));
        return;
    }
    for(int i=0;i<n;i++){
        a[i]+=1;
        dfs(n,m-1);
        a[i]-=1;
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(n,m);
    int ma=-1e9;
    for(int i=0;i<k.size();i++){
        if(k[i]>ma) ma=k[i];
    }
    cout<<ma;
    return 0;
}
