//TYZ lizihan SN-J00645

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,L,sum[200005][30],num[200005];
struct node{
	int l;char c;
}a[200005];

int query(int x,char c){
	int ans=0,p=0;
	for(int i=20;i>=0;i--){
		if(p+(1<<i)<=n&&num[p+(1<<i)]<=x)p+=(1<<i);
	}
	ans=sum[p][c-'a'];
	if(p<n&&a[p+1].c==c)ans+=x-num[p];
	return ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
		num[i]=num[i-1]+a[i].l;
		for(int j=0;j<26;j++)sum[i][j]=sum[i-1][j];
		sum[i][a[i].c-'a']+=a[i].l;
		L+=a[i].l;
	}
	int d=0,ans=0;
	for(int i=1;i<=n;i++){
		int l=d+1,r=min(L/2,d+a[i].l);
		int p=query(L-l+1,a[i].c)-query(L-r,a[i].c);
		ans+=(r-l+1-p);
		d+=a[i].l;
		if(r==L/2)break;
	}
	cout<<ans;	
	
	return 0;
}

//zhe ti za zhe me nan???
