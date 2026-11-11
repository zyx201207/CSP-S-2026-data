/*#include<bits/stdc++.h>
const int slen=5e5+10;
using namespace std;
long long a[slen],pre[slen];
int main(){
  freopen("crystal4.in","r",stdin);
  //freopen("crystal.out","w",stdout);
  int n;long long m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
  int ans=0;
  for(int i=1;i<=n;i++){
  	long long sum=a[i]*i-pre[i];
  	if(sum>m)break;
  	ans=i;
  }
  cout<<ans;
  return 0;
}*/
#include<bits/stdc++.h>
const int slen=5e5+10;
using namespace std;
long long a[slen],pre[slen];
long long n,m;
bool check(int ch){
  for(int i=1;i+ch<=n;i++){
  	int sum=(a[i+ch]*ch)-(pre[i+ch]-pre[i-1]);
  	if(sum<=m)return 1;
  }
  return 0;
}
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
  int l=0,r=n,ans=0;
  while(l<=r){
  	int mid=(l+r)>>1;
  	if(check(mid)==1){
  	  ans=mid;
  	  l=mid+1;
	}
	else r=mid-1;
  }
  cout<<ans;
  return 0;
}