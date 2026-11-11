#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	ll l,r;
	char c; 
};
int n,tot1,tot2;
int fl=0;
ll L,a[N];
char c[N];
node x[N],y[N];
ll merge(int i,int j){
	if(y[j].r<=x[i].r) fl=1;
	else fl=0;
	ll LL=max(x[i].l,y[j].l);
	ll RR=min(x[i].r,y[j].r);
	if(LL>RR){
		return 0;
	}
	else{
		if(x[i].c==y[j].c) return 0;
		return RR-LL+1;
	} 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	ll sum=1;
	for(int i=1;i<=n;i++){
		x[++tot1].c=c[i];
		x[tot1].l=sum;
		x[tot1].r=sum+a[i]-1;
		sum+=a[i];
		if(x[tot1].r> L/2) break;
	}
	sum=L;
	for(int i=n;i>=1;i--){
		y[++tot2].c=c[i];
		y[tot2].l=L-sum+1;
		y[tot2].r=L-(sum-a[i]+1)+1;
		sum-=a[i]; 
		if(y[tot2].r>L/2) break;
	}
	x[tot1].r=L/2;
	y[tot2].r=(L+1)/2;
	while(x[tot1].l>L/2) tot1--;
	while(y[tot2].l>L/2) tot2--;
	for(int i=1;i<=tot1;i++){
	//	cout<<x[i].l<<' '<<x[i].r<<' '<<x[i].c<<"\n";
	}
//	cout<<"\n";
	for(int i=1;i<=tot2;i++){
	//	cout<<y[i].l<<' '<<y[i].r<<' '<<y[i].c<<"\n";
	}
	ll ans=0;
	for(int i=1,j=1;i<=tot1;i++){
	//	cout<<i<<":";
		for(ll k;j<=tot2;j){
			k=merge(i,j);
		//	cout<<j<<" ";
			//	cout<<i<<' '<<j<<' '<<fl<<"\n";
			ans+=k;
			if(fl==0) break;
			else j++;
		} 
	//	cout<<"\n";
	}
	cout<<ans;
//	cout<<ans;
	return 0;
} 

/*



*/
