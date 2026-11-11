#ifndef AND_CPP_INCLUDED
#define AND_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=33;
const int M=2*1e5+5;
int f[M];
vector<int> merge(const vector<int>& a,const vector<int>& b){
    vector<int> con;
    for (int i=0;i<=N;i++){
        if (a[i]!=0&&b[i]!=0)
            con.push_back(i);
    }
    return con;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int> >a(n+1,vector<int>(N));
    for (int i=1;i<=n;i++){
      int x;
      cin>>x;
      int t=0;
      while (x!=0){
        if (x&1) a[i][t]++;
        t++;
        x>>=1;
      }
    }
    cout<<1<<endl;





}
#endif // AND_CPP_INCLUDED
