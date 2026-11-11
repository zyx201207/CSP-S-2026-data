#include <bits/stdc++.h>

using namespace std;

int t[505][505];

int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  int c,n,m,d,q;
  cin>>c>>n>>m>>d>>q;
  int w[500005],k[505];
  for(int i=1;i<=m;i++){
    cin>>w[i];
  }
  for(int i=1;i<=n;i++){
    cin>>k[i];
    for(int j=1;j<=k[i];j++){
      int a;
      cin>>a;
      cin>>t[j][a];
    }
  }
  for(int r=1;r<=q;r++){
    int x,y;
    cin>>x>>y;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k[i];j++){
      cout<<t[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
5 3
0 7
*/
