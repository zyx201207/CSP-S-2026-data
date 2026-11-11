#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200100],t1[31],t2[31],cnt=0,maxx=0;
struct QvQ{
	int id,e[31];
}b[200100];
bool cmp (QvQ a,QvQ b){
	for(int i=1;i<=cnt;i++){
		if(a.e[t2[i]]!=b.e[t2[i]]){
			return a.e[t2[i]]>b.e[t2[i]];
		}
	}
	return a.id>b.id;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		b[i].id=i;
		int x=a[i];
		int num=1;
		while(x!=0){
			b[i].e[num]=x%2;
			t1[i]+=x%2;
			x>>=1;
			num++;
		}
	}
	if(n==m){
		int ddn=a[1];
		for(int i=2;i<=n;i++){
			ddn&=a[i];
		}
		cout<<ddn;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	bool is=true;
	for(int i=31;i>=1;i--){
		if(t1[i]>=m){
			cnt++;
			t2[cnt]=i;
			is=false;
		}
	}
	sort(b+1,b+n+1,cmp);
	if(is){
		cout<<0;
		return 0;
	}
	ans=a[b[1].id];
	for(int i=2;i<=m;i++){
		ans&=a[b[i].id];
	}
	cout<<ans;
	return 0;
}
