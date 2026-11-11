#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	vector<int>pre(n,-1);
	vector<int>f(m,-1);
	vector<int>ans(m,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		pre[i]=f[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<m;k++){
				if(pre[k]<=f[j]||f[j]==-1){
					++ans[k];
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<(ans[i]/*-i-1*/)/*%m*/<<' ';
	}
	return 0;
}
