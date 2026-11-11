#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mn=6e5+6;
ll n,m,a[mn],ans,sum;
ll st[mn][21],x;
inline quz(int u,int v){
	ll bc=0;
	while(v!=u){
		ll a=1;
		int k=0;
		while(u+a<=v){
			k++;
			a*=2;
		}
		bc+=st[v][k-1];
		v-=a/2;
	}
	return bc;
}
inline ll cif(int u,int k){
	ll i=1;
	u+=k;
	while(k--) i*=2;
	u-=i;
	if(u<0) u=0;
	return u; 
}
inline void cre_bia(){
	int k=log2(n);
	for(int j=1;j<=k+1;j++)
		for(int i=1;i<=n;i++)
			st[i][j]=st[i][j-1]+st[cif(i,j)][j-1];
}
int main ( ) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		st[i][0]=a[i]-a[i-1];
	st[1][0]=0;
	cre_bia();
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<5;j++)
//		cout<<st[i][j]<<' ';
//		cout<<endl;
//	}
//for(int i=1;i<=3;i++){ 
//	cin>>n>>m;
//	cout<<quz(n,m);
//}

	for(int i=n;i>0;i--){
		ans=0;sum=0;
		int j=i-1;
		while(1){
			if(!j){
				ans++;
				break;
			}
			sum+=quz(j,i);
			ans++;
			if(sum>m) break;
			j--;
		}
		if(ans-1>x) x=ans-1;
		if(!j) break;
	}
	cout<<x+1;
	return 0;
}
