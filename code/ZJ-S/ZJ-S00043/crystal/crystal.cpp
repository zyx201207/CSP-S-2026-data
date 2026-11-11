#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int s[500010];
int read(){
	int sum=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=(sum<<1)+(sum<<3)+c-'0';
		c=getchar();
	}
	return sum*w;
}
bool check(int i,int j){
	if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m){
		return 1;
	}
	return 0;
}
int find(int i){
	int l=1,r=i,mid,ans=-1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(i,mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	int j=0;
	for(int i=1;i<=n;i++){
		j=find(i);
		if(j!=-1)ans=max(i-j+1,ans);
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
//O(nlogn)
