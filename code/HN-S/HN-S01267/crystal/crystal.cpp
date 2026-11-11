#include<bits/stdc++.h>
using namespace std;

struct shuijin{
	long long nl;
	long long wz;
}a[100005];
long long n,m;
long long b[100005]={};
int mcnt=-100000;
void dfs(long long cs){
	if(cs>=0){
		for(int v=1;v<=n;v++){
			b[v]=a[v].nl;
		}
		sort(b+1,b+n+1);
		int l=1,r=1,cnt=0;
		while(r<=n+1){
			if(b[r]!=b[l]){
				mcnt=max(mcnt,cnt);
				l=r;
				cnt=0;
			}
			cnt++;
			r++;
		}
		if(cs==0){
			return ;			
		}
	}
	for(int i=1;i<=n;i++){
		a[i].nl++;
		dfs(cs-1);
		a[i].nl--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].nl;
		a[i].wz=i; 
	}
	dfs(m);
	cout<<mcnt;
} 
