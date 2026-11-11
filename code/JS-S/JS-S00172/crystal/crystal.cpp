#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1e18;
ifstream fin("crystal.in");
ofstream fout("crystal.out");

const int maxn=5e5+10;
int a[maxn];
int pre[maxn];
int n,m;

ll sum(int l,int r){
    return pre[r]-pre[l-1];
}
ll cost(int l,int r){
    if(l>n||r>n)return inf;
    int nodes=r-l;
    return a[r]*nodes-sum(l,r-1);
}

int main(){
    fin>>n>>m;
    pre[0]=0;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    int l=1,r=1;
    int best=0;
    while(l<=r&&r<=n){
        while(cost(l,r+1)<=m)r++;
        best=max(best,r-l+1);
        l++;
    }
    fout<<best;
}