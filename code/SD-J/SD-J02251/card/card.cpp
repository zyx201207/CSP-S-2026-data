/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f[N];//这个数字是否出现，出现在哪里
int ans[N];//每个数字的出现次数
int a[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn_tmp=0;
	int flag=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxn_tmp=max(maxn_tmp,a[i]);
		if(maxn_tmp!=a[i]) flag=1;
	}
	if(flag==1){//nm
		for(int i=1;i<=n;++i){//第i局
			for(int j=i;j<=n;++j){
				if(f[a[j]]!=0){
					//之前有
					for(int k=f[a[j]];k<=j;++k) f[a[k]]=0; 	
				}
				f[a[j]]=j; 
			} 
			for(int i=1;i<=m;++i){
				if(f[i]) {
					ans[i]++;
					f[i]=0;
				} 
			}
			
		}
		for(int i=1;i<=m;++i){
			cout<<ans[i]<<" ";
		}
	}
	else{//A
		for(int i=1;i<=n;++i){
			f[a[i]]=i;
		}
		for(int i=1;i<=m;++i){
			cout<<f[i]<<" ";
		}
	}
	
	return 0;
}

