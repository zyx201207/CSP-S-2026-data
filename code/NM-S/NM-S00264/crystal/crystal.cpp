#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int ma=-1;
long long int a[500010],cf[500010],pre[500010];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++) cf[i]=a[i+1]-a[i];
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]+cf[i-1];
	for(int i=2;i<=n;i++){
		int l=i-1;
		long long ls=m;
		while(ls>0&&l>=1){
			long long s=pre[i]-pre[l];
			ls-=s;
			l--;
		}
		ma=max(ma,i-l);
	}
	cout<<ma;
	return 0;
}
