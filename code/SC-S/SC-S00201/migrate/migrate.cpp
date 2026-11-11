#include<bits/stdc++.h>
using namespace std;
int x[2000007];
int s[2000007];
long long n,d;
long long pum=0;
void dfs(long sum,long long i,long long num,long long sum1){
	if(i>n){
		return ;
	}
	if(num>=sum && i<n){
		return ;
	}
	else if(num==sum && i==n){
		pum++;
		return ;
	}
	if(!(sum1+x[i]>d)){
		dfs(sum,i+1,num,sum1+x[i]-x[i-1]);
		dfs(sum,i+1,num+1,0);
	}
	else{
		dfs(sum,i+1,num+1,0);
	}
	
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		pum=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		long long num=0,sum=1;
		for(int j=2;j<=n;j+=1){
			//cout<<"000 \n";
			if(num+x[i]-x[i-1]>d){
				sum++;
				num=0;
				continue;
			}
			num+=x[i]-x[i-1];
		}
		dfs(sum,2,0,0);
		cout<<pum<<"\n"; 
	}
	return 0;
}
