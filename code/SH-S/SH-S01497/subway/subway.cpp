#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
const ll MAXN=1e9+7;
ll w[N];
ll dBF[1009][1009];
ll c,n,m,d,q;
void solveBF(){
	for(ll i=1;i<=m+n;i++){
		for(ll j=1;j<=m+n;j++){
			dBF[i][j]=MAXN;
		}
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll op1,op2;
			cin>>op1>>op2;
			dBF[op1][m+i]=op2;
			dBF[m+i][op1]=op2;
		}
	}
	for(ll i=1;i<=m+n;i++) dBF[i][i]=0;
	for(ll k=1;k<=m+n;k++){
		for(ll i=1;i<=m+n;i++){
			for(ll j=1;j<=m+n;j++){
				dBF[i][j]=min(dBF[i][j],dBF[i][k]+dBF[k][j]);
			}
		}
	}
	while(q--){
		ll a,b;
		cin>>a>>b;
		cout<<dBF[a][b]+w[a]+w[b]<<endl;
	}
}
void solveA(){
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			dBF[i][j]=MAXN;
		}
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k/2;j++){
			ll op1,op2,op3,op4;
			scanf("%lld %lld %lld %lld",&op1,&op2,&op3,&op4);
			dBF[op1][op3]=op2+op4;
			dBF[op3][op1]=op2+op4;
		}
	}
	for(ll i=1;i<=m;i++) dBF[i][i]=0;
	for(ll k=1;k<=m;k++){
		for(ll i=1;i<=m;i++){
			if(dBF[i][k]>=1e9+7){
			    continue ;
			};
			for(ll j=1;j<=m;j++){
				dBF[i][j]=min(dBF[i][j],dBF[i][k]+dBF[k][j]);
			}
		}
	}
	while(q--){
		ll a,b;
		cin>>a>>b;
		cout<<dBF[a][b]+w[a]+w[b]<<endl;
	}
}
ll dC[N][3];
void solveC(){
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll op1,op2;
			cin>>op1>>op2;
			dC[op1][i]=op2;
		}
	}
	ll bri=MAXN;
	for(ll i=1;i<=m;i++){
		if(dC[i][1]!=0&&dC[i][2]!=0) bri=min(bri,dC[i][1]+dC[i][2]);
	}
	while(q--){
		ll a,b;
		cin>>a>>b;
		ll ans=MAXN;
		if(dC[a][1]!=0&&dC[b][1]!=0) ans=min(ans,dC[a][1]+dC[b][1]+w[a]+w[b]);
		if(dC[a][2]!=0&&dC[b][2]!=0) ans=min(ans,dC[a][2]+dC[b][2]+w[a]+w[b]);
		if(dC[a][1]!=0&&dC[b][2]!=0) ans=min(ans,dC[a][1]+dC[b][2]+w[a]+w[b]+bri);
		if(dC[a][2]!=0&&dC[b][1]!=0) ans=min(ans,dC[a][2]+dC[b][1]+w[a]+w[b]+bri);
	    cout<<ans<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	if(c<=8) solveBF();
	else if(c<=11) solveA();
	else if(c>=20&&c<=21) solveC();
	else solveBF();
	return 0;
}
