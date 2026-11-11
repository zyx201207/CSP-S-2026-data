#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500010],pre[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	for(int i=1,j=1;i<=n;){
		long long w=a[i]*(i-j+1)-(pre[i]-pre[j-1]);
		//cout<<i<<" "<<j<<" "<<w<<endl;
		if(w<=m){
			ans=max(ans,i-j+1);
			i++;
		}
		else if(w>m){
			i++;
			j++;
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
