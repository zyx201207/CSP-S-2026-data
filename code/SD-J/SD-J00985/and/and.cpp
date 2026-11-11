#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,maxn;
const int N=2e5+100;
long long a[N][40];
void work(long long i,long long x){
	long long j=0;
	while(x){
		if(x&1){
			a[i][j]=1;
			maxn=max(maxn,j);
			a[n+1][j]+=1;
		}
		j++;
		x/=2;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		work(i,x);
	}
	queue<int > nw,ls,nw2;
	for(int i=maxn;i>=0;i--){
		if(a[n+1][i]<m){
			continue;
		}
		if(ls.empty()){
			ans+=(1ll)<<i;
			for(int j=1;j<=n;j++){
				if(a[j][i]==1){
					ls.push(j);
				}
				
			}
			continue;
		}
		while(!ls.empty()){
			long long u=ls.front();
			ls.pop();
			if(a[u][i]==1)nw.push(u);
			else nw2.push(u);
		}
		if(nw.size()<m){
			while(!nw.empty()){
				long long u=nw.front();
				nw.pop();
				ls.push(u);
			}
			while(!nw2.empty()){
				long long u=nw2.front();
				nw2.pop();
				ls.push(u);
			}
		}else{
			ans+=1ll<<i;
			while(!nw.empty()){
				long long u=nw.front();
				nw.pop();
				ls.push(u);				
			}
			while(!nw2.empty()){
				nw2.pop();
			}
		}
//		cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
