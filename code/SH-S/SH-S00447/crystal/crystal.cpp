#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int d[500010];
int maxi[500010];
int len,val,ans,m,l;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	queue<int> q;
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		d[i]=a[i]-a[i-1];
	}
	l=2;
	q.push(a[1]);
	for(int i=2;i<=n;++i){
		if(val+d[i]*(i-l+1)<=m){
			val+=d[i]*(i-l+1);
			len++;
			maxi[i]=len;
			q.push(a[i]);
		}
		else{
			val+=d[i]*(i-l+1);
			len++;
			q.push(a[i]);
			while(val>m&&!q.empty()){
			//	cout<<len<<' ';
				int v=q.front();
				q.pop();
				val-=a[i]-v;
				len--;
				l++;
			}
			maxi[i]=len;
		}
//		if(i==2)cout<<'p';
		//printf("%lld ",maxi[i]);
	}
	for(int i=2;i<=n;++i){
		ans=max(ans,maxi[i]);
	}
	cout<<ans+1;
	return 0;
}
