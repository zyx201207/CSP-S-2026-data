#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
long long ans[M];
int put(int i,int n,int m){
	stack<int>st;
	int len=0;
	map<int,int>mp;
	for(int j=i;j<=n;j++){
		if(mp.count(a[j])==0){
			st.push(a[j]);
			mp[a[j]]=++len;
		}else{
			int cnt=len;
			while(cnt>=mp[a[j]]){
				st.pop();
				len--; cnt--;
			}
			st.push(a[j]);
			mp[a[j]]=++len;
		}
	}
	while(!st.empty()){
		int cur=st.top(); st.pop();
		if(cur==m) return 1;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			int z=put(i,n,j);
			ans[j]+=z;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<"\n"; 
	stdin.fclose();
	stdout.fclose();
	return 0;
}
