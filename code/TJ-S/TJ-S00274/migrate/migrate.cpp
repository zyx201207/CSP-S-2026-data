#include<bits/stdc++.h>
using namespace std;
int c,t,a[100001],mi[100001],ans,num[100001],sum,d,n;
void dfs(int u,int l){

	if(l<=mi[u]){
		if(l<mi[u]){
			if(num[u]==2){
				sum--;
			}
			num[u]=1;
			mi[u]=l;
		}else if(mi[u]==l){
			num[u]++;
			if(num[u]==2){
				sum++;
			}
			if(num[u]>2){
				sum--;
			}
		}	
	}else{
		return;
	}
//	cout<<u<<" "<<l<<" ";
//	for(int i=1;i<=n;i++){
//		cout<<mi[i]<<" ";
//	}
//	cout<"        ";
//	for(int i=1;i<=n;i++){
//		cout<<num[i]<<" ";
//	}
//	cout<<endl;
	for(int i=u-1;i>=1;i--){
		if(a[u]-a[i]>d){
			break;
		}
		dfs(i,l+1);
	}
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]>d){
			break;
		}
		dfs(i,l+1);
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=1;i++){
			sum=0;
			for(int j=1;j<=n;j++){
				mi[j]=n+1;
				num[j]=0;
			}
			dfs(i,0);
			ans+=sum;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


