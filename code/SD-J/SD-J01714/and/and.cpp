#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
bool v[220000][35];
struct op{
	long long g,l;
}a[220000];
bool cmp(op a,op b){
	return a.l>b.l;
}
int main(){
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
  cin>>n>>m;
for(int i=1;i<=n;i++){
  	cin>>a[i].g;
  }
  for(int i=1;i<=n;i++){
  	for(int j=0;j<=30;j++){
  	if(a[i].g&(1<<j)) a[i].l++;
  } 
  } 
  sort(a+1,a+n+1,cmp);
  ans=a[1].g;
  for(int i=2;i<=m;i++){
  	ans=(a[i].g&ans);
  }
  cout<<ans;
	return 0;
} 
    
