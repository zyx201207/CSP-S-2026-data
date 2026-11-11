#include<bits/stdc++.h>
using namespace std;
const long long maxn=2000000;
long long n,d,a[maxn+5],ans;
long long val,cnt;
void dfs(int u,int p,int lst){
	if(u==p){
		if(lst==val){
			cnt++;
		}else if(lst<val){
			val=lst;
			cnt=1;
		}
		return ;
	}
	for(int v=u+1;v<=p;v++){
//		cout<<"*"<<u<<" "<<v<<"\n";
		if(a[v]-a[u]>d){
			break;
		}
		dfs(v,p,lst+1);
	}
	return ;
}
bool check(int u,int v){
	val=0x3f3f3f3f3f3f3f3f;
	cnt=0;
	dfs(u,v,0);
	if(val==0x3f3f3f3f3f3f3f3f){
		return 0;
	}
	if(cnt==2){
		return 1;
	}
	return 0;
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
void solveA(){
	long long del=a[2]-a[1];
	d=d/del;
	if(d<2||d>=n-1){
		cout<<0<<"\n";
		return ;
	}
	ans=n-d*2+1;
	cout<<ans<<"\n";
}
void solve(int c){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==0){
		solveA();
	}else if(c==1||c==2){
		solve1();
	}else if(c==11||c==12){
		solveA();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
//	cout<<c<<" "<<t<<"\n";
	while(t--){
//		cout<<"T"<<t<<"\n";
		solve(c);
	}
	return 0;
}