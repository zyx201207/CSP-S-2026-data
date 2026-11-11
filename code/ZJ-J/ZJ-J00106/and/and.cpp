#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],n,m;
bool t[N][31];
int maxn,len,cnt[31];
bool vis[N];
int ans;
void f(int id,int x){
	int d=x,c=len;
	while(d){
		c--;
		d/=2;
	}
	d=x;
	int l=len-c,lt=c;
//	while(l){
//		l--;
//		d*=2;
//	}
	while(d){
		c++;
		t[id][len-c+1+lt]=d%2;
		d/=2;
	}
	return;
}
void F_maxlen(){
	while(maxn){
		len++;
		maxn/=2;
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	F_maxlen();
	for(int i=1;i<=n;i++){
		f(i,a[i]);
/*		for(int j=1;j<=len;j++){
			cout<<t[i][j];
		}
		cout<<'\n';
*/		for(int j=1;j<=len;j++){
			cnt[j]+=t[i][j];
		}
	}
	int first=1,sum=0;
	while(cnt[first]<m)first++;
	for(int i=first;i<=len;i++){
		ans*=2;
		if(cnt[i]<m)continue;
		sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(!t[j][i]){
				vis[j]=true;
				continue;
			}
			sum++;
		}
		if(sum>=m)ans++;
	}
	cout<<ans;
	return 0;
}