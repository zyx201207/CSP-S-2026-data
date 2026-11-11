#include<bits/stdc++.h>
using namespace std;
struct A{
  int fi;
  int se;
  int nu;
}a[300001];
int b[500001];
bool cmp(A z,A y){
  return z.fi>y.fi;
}
int find(int y){
  int tol=y+1;
  while(1){
    if(a[tol].se>a[y].second) return tol;
    tol++;
  }
}
int main(){
  int n,m,x,t=1;
  cin>>m>>n;
  for(int i=1;i<=m;i++){
    cin>>x;
    b[i]=x;
    if(a[x].nu==0){
      a[x].nu++;
      a[x].fi=i;
      a[x].se=i;
  }else{
      a[x].nu++;
      a[x].se=a[x].fi;
      a[x].fi=i;
  }
  sort(a+1,a+m+1,cmp);
  for(int i=1;i<=m;i++){
    if(i>a[t].se){
      t=find(t);
    }
    for(int i=a[t].fi;i<=n;i++){
      cout<<b[i]<<"/n";
    }
  }
  return 0;
}
