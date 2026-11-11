#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],b[500010],S[500010];
void sv1(){
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)S[i]=S[i-1]+b[n-i];
	for(int i=1;i<=n;i++){
		long long nm=m;
		int ths=0;
		for(int j=i;j<=n;j++){
			if(nm>=S[j]-S[i])nm-=(S[j]-S[i]),ths++;
		}
		ans=max(ths,ans);
	}
	cout<<ans;
	return ;
}
void sv2(){
	long long gc=1e18;
	for(int i=2;i<=n;i++)gc=min(abs(a[1]-a[i]),gc);
	if(gc!=0)m/=gc;
	else {
		cout<<n;return ;
	}
	long long l=1,r=1e9+7,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(mid*(mid-1)/2<=m)l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<min((int)ans,n);
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=10000)sv1();
	else sv2();
}