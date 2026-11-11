#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010]={0xffffffffffffffff};
int lowbit(int x){return x&-x;}
bool cmp(int a,int b){
	int t1=a,t2=b,ca=0,cb=0; 
	while(t1) t1-=lowbit(t1),ca++;
	while(t2) t2-=lowbit(t2),cb++;
	if(ca==cb) return a>b;
	return ca>cb;}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) a[i]&=a[i-1];
	cout<<a[m]; 
	return 0;}
