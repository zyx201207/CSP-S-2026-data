#include<bits/stdc++.h>
using namespace std;
long long A[300000];
vector<long long>v;
int n,m;
void dfs(int xb,long long x,int step){
	if(step==m){
		v.push_back(x);
		return;
	}
	for(int i=xb+1;i<n;i++){
		dfs(i,A[i]&x,step++);
	}
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	if(m==1){
		cout<<0;
	}else{
		for(int i=0;i<=n-m;i++){
			dfs(i,A[i],1);
		}
		sort(v.begin(),v.end(),cmp);
		cout<<v[0];
	}
	return 0;
}
