#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	int a[10005];
	int ans[10005];
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		ans[i]=max(a[i+1],a[i])-min(a[i+1],a[i]);
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ans[j+1]<ans[j]){
				ans[j]=ans[j+1];
			}
		}
	} 
	
	
	int beifen[10005]; 
	for(int i=1;i<=n;i++){
		beifen[i]=ans[i];
	}
	
	
	while(m!=0){
		int i=1;
		for(int j=i+1;j>=1;j--){
			ans[i]+=ans[j-1];
		} 
		i++;
		m-=beifen[i]; 
	}
	
	
	for(int k=1;k<=n;k++){
		if(ans[k]!=beifen[k]){
			num++;
		}
	} 
	cout<<num;
	return 0; 
}
