#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int sh[2000010]={0};
int ans[2000010]={0};
int c,t,n,m;
void fly(){
	int waht=0;
	for(int i=1;i<=n;i++){
		sh[i]=0;
		ans[i]=0;
	}
	ans[1]=1; 
	for(int x=1;x<=n;x++){
		int far=a[x]+m;
		cout<<x<<":"<<endl;
		if(ans[x]==0){
			continue;
		}
		if(ans[x]==2){
			waht++;
		}
		ans[x]=1;
		for(int i=x+1;i<=n&&a[i]<=far;i++){
			if(sh[i]>sh[x]+1||sh[i]==0){
				sh[i]=sh[x]+1;
				ans[i]=ans[x];
				cout<<i<<"new"<<endl;
			}else if(sh[i]==sh[x]+1){
				ans[i]++;
				cout<<x<<"to"<<i<<endl;
			}
		}
	}
	cout<<waht<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		fly();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
