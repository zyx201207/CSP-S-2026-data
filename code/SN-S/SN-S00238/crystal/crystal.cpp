#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],b[500001],sum,l,ans,cnt,p,h;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
	}
	sort(a+1,a+n+1);
	p=a[n]*n;
	h+=m;
	if(h>=p){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
		sum=max(sum,b[i-1]);
	}
	for(int i=1;i<n;i++){
		if(b[i]==sum){
			l=i;
		}
	}int w=m;
	int k=0;
	cnt=1;
	ans=1;
	for(int i=l-1;i>=1;i--){
		k+=b[i];
		if(m-k>=0){
			m-=k;
			ans++;
		}else{
			break;
		}
	}
	k=0;
	m=w;
	int ans1=1;
	for(int i=l;i>=1;i--){
		k+=b[i];
		if(m-k>=0){
			m-=k;
			ans1++;
		}else{
			break;
		}
	}
	m=w;
	k=0;
	for(int i=n;i>l;i--){
		k+=b[i-1];
		if(m-k>=0){
			m-=k;
			cnt++;
		}else{
			break;
		}
	}
	int cnt1=1;
	m=w;
	k=0;
	for(int i=n;i>=l;i--){
		k+=b[i-1];
		if(m-k>=0){
			m-=k;
			cnt1++;
		}else{
			break;
		}
	}
	cnt=max(cnt,cnt1);
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
}
