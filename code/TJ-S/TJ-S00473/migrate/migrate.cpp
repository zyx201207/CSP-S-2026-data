#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[100004];
void dfs(int i,int j){
	for(int j=i;a[i]-a[j]<d;j--){		
		d[i][j]++;
		dfs(j);
	}
	if(i==1){
		return;
	}		
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=0;j<t;j++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				dfs(i,j);
			}
		}
	}
		for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if (a[i][j]==2){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

