#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int M = 1e5+5;
struct SGT{
    int c[M<<2];
    void build(int p,int l,int r){
        c[p] = 0;
        if(l==r)return;
        build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    }
};
mt19937 rd(random_device{}());
int a[M];
signed main(){
    freopen(".in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n = 1e3;
    L(i,1,n)a[i] = rd(),cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
/*

Oct31==Dec25?

*/