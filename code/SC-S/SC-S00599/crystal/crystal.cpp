#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const int N = 5e5+5;
using namespace std;
int n;
ll m,ans,cnt,l=1,r=1;
ll a[N],b[N],c[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	b[1]=0;
	for(int i=1;i<=n;i++){
		c[i]=b[i]+c[i-1];
	}
	while(r<=n){
		while(cnt>m){
			ans=max(ans,r-l);
			l++;
			cnt-=c[r];
			cnt+=c[l];
		}
		r++;
		cnt+=(r-l)*b[r];
	}
	ans=max(ans,r-l);
	cout <<ans <<endl;
	return 0;
}
