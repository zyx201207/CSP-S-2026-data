//CSP-S 2026 RP++
#include<bits/stdc++.h>
#define ll long long
#define gc getchar()

using namespace std;

const int N=5e5+100;

int n,m;
ll a[N];
int ans;

inline ll rd(){
	ll x=0,f=1;char ch=gc;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=gc;}
	while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return x*f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();
	m=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+n+1);
	int p=1;
	ll sum=0;
	for(int i=1;i<=n;i++){
		while(p<i&&sum+(a[i]-a[i-1])*(i-p)>m){
			p++;
			sum-=(a[i-1]-a[p]);
		}
		if(sum+(a[i]-a[i-1])*(i-p)<=m){
			sum+=(a[i]-a[i-1])*(i-p);
			ans=max(ans,i-p+1);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7