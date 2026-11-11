#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define INF 1e9
ll c,n,m,d,q,w[500005],ta,tt,x,y,k,mn=INF;
ll a[505][2],t[505];
bool v[500005];
void s(ll l,ll o){
	if(l==y){
		mn=min(mn,o);
		return;
	}
	for(ll i = 0;i<n;i++){
		if(!v[a[i][1]]&&a[i][0]==l){
			v[a[i][1]]=1;
			s(a[i][1],o+t[i]);
			v[a[i][1]]=0;
		}
		if(!v[a[i][0]]&&a[i][1]==l){
			v[a[i][0]]=1;
			s(a[i][0],o+t[i]);
			v[a[i][0]]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(ll i = 1;i<=n;i++){
		cin >> k;
		for(ll j = 1;j<=k;j++){
			cin >> ta >> tt;
			if(j==1){
				a[i][1]=ta;
				t[i]+=tt;
			}else{
				a[i][0]=ta;
				t[i]+=tt;
			}
		}
	}
	for(ll r=0;r<q;r++){
		cin >> x >> y;
		ll crt=w[x]+w[y];
		v[x]=1;
		s(x,0);
		v[x]=0;
		cout << crt+mn << endl;
	}
	return 0;
}
