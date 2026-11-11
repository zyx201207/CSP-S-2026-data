#include<bits/stdc++.h>
using namespace std;

const long long N=2e6+10;
long long line[N];
long long n,d;
void init(){
	cin>>n>>d;
	for(long long i=1;i<=n;i++) cin>>line[i];
}
long long cnt=0,minn=1e18;
void dfs(long long cur,long long aim,long long step){
	if(cur==aim){
		
		if(step<minn){
			cnt=1;
			minn=step;
			return ;
		}else if(step==minn){
			cnt++;
			return ;
		}else{
			return ;
		}
	}
	if(step>=minn) return ;
	for(long long i=cur+1;i<=n;i++){
		if(abs(line[i]-line[cur])<=d&&i<=aim){
			dfs(i,aim,step+1);
		}else{
			break;
		}
	}
	return ;
}

void solve1(){
	long long res=0;
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			cnt=0;
			minn=1e18;
			dfs(i,j,0);
			if(cnt==2) res++;
		}
	}
	cout<<res<<"\n";
}

void solve2(){
	long long cha=line[2]-line[1];
	if(d/cha<=1){
		cout<<0<<"\n";
		return ;
	}
	long long tjg=d/cha,res=0;
	for(long long i=1;i<=n-tjg-1;i++){
		long long tmp;
		tmp=n-i-tjg-(n-i-tjg)/tjg;
		res+=tmp;
	}
	cout<<res<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long C,T;
	cin>>C>>T;
	while(T--){
		init();
		if(n<=300) solve1();
		else if(C>=11&&C<=12) solve2();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
8 3
1 2 3 4 5 6 7 8

0 1
8 6
2 4 6 6 10 12 14 16

*/