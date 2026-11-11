#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000001],u,v;
int dfs(int step,int s,int k){
	int ans=0;
	if(step==k-1){
		if(x[v]-x[s]>d) return 0;
		else return 1;
	}
	for(int i=s+1;i<=v-(k-step)+1;i++){
		if(x[i]-x[s]<=d) ans+=dfs(step+1,i,k);
	}
	return ans;
}
bool im(){
	int s=u,cnt=1;
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[i-1]>d) return 0;
		if(x[i]-x[s]>d){
			s=i-1;
			cnt++;
		}
	}
	if(dfs(0,u,cnt)==2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+3;j<=n;j++){
				u=i;
				v=j;
				if(im()) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
