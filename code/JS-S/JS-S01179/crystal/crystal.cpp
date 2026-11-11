#include<bits/stdc++.h>
using namespace std;
//#define int long long;
int n;
long long m;
int a[50005];
int c[50005];
int ans[50005];
int q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+1+n);
for(int i=1;i<n;i++){
c[i]=a[i+1]-a[1];
}
for(int i=1;i<n;i++){
q=i;
ans[q]=0;
while(m>0&&q>0){
m--;
c[q]--;
c[q-1]++;
if(m==0)break;
if(c[q]==0){
  if(ans[i]==0)ans[i]+=2;
  ans[i]++;
  q--;
  if(q==0)break;
}
}
}
sort(ans+1,ans+n-1);
cout<<ans[n-1];
	return 0;
}


