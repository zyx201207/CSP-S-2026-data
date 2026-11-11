#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
bool cho[20];
int x[N];
int res[20];
int nn;
int c,t,n,d;
int ans_cnt;
int minn;
int nl,nr;
int fl;
void dfs(int st){
	if(st==nn+1){
		int lst_pos=x[nl];
		int fin_pos=x[nr];
		int f=0;
		int cnt=0;
		for(int i=1;i<=nn;i++){
			if(res[i]==0) continue;
			else{
				cnt++;
				int dis=x[i+nl]-lst_pos;
				if(dis>d){
					f=1;break;
				}
				lst_pos=x[i+nl];
			}
		}
		if(fin_pos-lst_pos>d) f=1;
		if(f==0&&fl==0){
			fl=1;minn=cnt;
		}
		if(f==0&&cnt==minn){
			ans_cnt++;
		}
		return;
	}
	res[st]=0;
	dfs(st+1);
	res[st]=1;
	dfs(st+1);
}
bool che(int l,int r){
	nl=l;
	nr=r;
	ans_cnt=0;
	fl=0;
	nn=r-l-1;
	dfs(1);
	if(ans_cnt==2) return true;
	return false;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==1||c==2){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					minn=n;
					if(che(i,j)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}	
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int del=x[2]-x[1];
			d/=del;
			if(d<=1){cout<<"0\n";continue;}
			int m=2*d-1;
			cout<<max(0ll,n-m)<<"\n";
		}	
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

*/