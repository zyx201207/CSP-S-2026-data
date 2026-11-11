#include<iostream>
using namespace std;
long long c,t,n,d,sum=0;
long long x[50010]={},ans[50010]={},amin[50010]={};
void dfs(int k,int depth){
	for(int i=1;x[k+i]-x[k]<=d && k+i<n;i=i+1){
		if(depth<amin[k+i]){
			amin[k+i]=depth;
			ans[k+i]=1;
		}
		else if(depth==amin[k+i]){
			ans[k+i]=ans[k+i]+1;
		}
		else{
			return ;
		}
		dfs(k+i,depth+1);
	}
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		cin>>n>>d;
		for(int i=0;i<n;i=i+1){
			cin>>x[i];
		}
		for(int i=0;i<n;i=i+1){
			for(int j=0;j<n;j=j+1){
				amin[j]=1000000000000000000;
				ans[j]=0;
			}
			dfs(i,1);
			for(int j=0;j<n;j=j+1){
				if(ans[j]==2){
					sum=sum+1;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
		t=t-1;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
