#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define db double 
const int N=2e5+10;
int a[N];
int v[N];
int t[N];
int ans=0;
int n,m;
void dfs(int pos){
	if(pos == m+1){
		int sum=a[t[1]];
		for(int i=2;i<pos;i++){
			sum&=a[t[i]];
		}
		ans=max(ans , sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			t[pos]=i;
			dfs(pos+1);
			v[i]=0;
		}
	}
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	dfs(1);
	cout<<ans;
	
	
	
	
	return 0;
}

