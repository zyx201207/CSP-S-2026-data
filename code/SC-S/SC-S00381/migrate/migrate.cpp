#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6;
ll n,d;
ll a[N+2];
ll tx[2][N+2];
int find(int begin,int end,ll t[],bool re=0){
	int pr=begin,tut=begin,l=1;
	t[l++]=begin;
	if(re==0){
		while(tut!=end){
			if(a[tut+1]-a[pr]>d) pr=tut,t[l++]=tut;
			tut++;
		}
		t[l]=end;
		return l;
	}
	else{
		while(tut!=end){
			if(a[pr]-a[tut-1]>d) pr=tut,t[l++]=tut;
			tut--;
		}
		t[l]=end;
		return l;
	}
}
bool f(int x,int y){
	int m=find(x,y,tx[0],0);
	find(y,x,tx[1],1);
	/*
	for(int i=1;i<=m;i++) cout<<tx[0][i]<<" ";
	cout<<"\n";
	for(int i=1;i<=m;i++) cout<<tx[1][i]<<" ";
	cout<<"\n";
	*/
	int c1=0;
	for(int i=1;i<=m;i++){
		if(tx[0][i]-tx[1][m-i+1]==0) ;//
		else if(tx[0][i]-tx[1][m-i+1]==1) c1++;
		else return false;
	}
	if(c1==1) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int yld,t;
	cin>>yld>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		//cout<<f(1,4);
		//return 0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f(i,j)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
