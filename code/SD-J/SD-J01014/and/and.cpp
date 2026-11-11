#include<bits/stdc++.h>
using namespace std;
long long dp[200001],n,k,a[200001],mm=0,a1[21];
bool b[21];
void dfs(int x,int y){
	if(x==k+1){
		long long m1=pow(2,31)-1;
		for(int i=1;i<=k;i++){
			m1=(m1&a1[i]);
		}
		mm=max(mm,m1);
	}
	for(int i=y;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			a1[x]=a[i];
			dfs(x+1,i+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1,1);
		cout<<mm;
	}
	else if(k==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mm=max(a[i]&a[j],mm);
			}
		}
		cout<<mm;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			mm=max(mm,a[i]);
		}
		cout<<mm;
	}
	
	return 0;
}

