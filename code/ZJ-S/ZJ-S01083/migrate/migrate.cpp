#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2100000],ans[2100000][2];
void dfs(int pos,int l){
	for(int i=pos+1;i<=n;i++){
		if(a[i]-a[pos]>d) return;
		else{
			//cout<<pos<<" "<<i<<"\n";
			if(l+1<ans[i][0]){
				ans[i][0]=l+1;
				ans[i][1]=0;
			}
			ans[i][1]++;
			dfs(i,l+1);
		} 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int cnt=0;
		for(int k=1;k<=n;k++){
			//cout<<"---Task---\n";
			for(int i=1;i<=n;i++) ans[i][1]=0,ans[i][0]=1e9;
			dfs(k,0);
			for(int i=1;i<=n;i++){
				//cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
				if(ans[i][1]==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
