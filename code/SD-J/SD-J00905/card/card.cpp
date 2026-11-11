#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[300005],ans[300005];
stack<int>t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[n]==1)ans[1]++;
			else if(a[i]==2&&a[n]==2)ans[2]++;
			else ans[1]++,ans[2]++;
		}
		cout<<ans[1]<<' '<<ans[2];
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)f[j]=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(t.top()!=a[j]){
					f[t.top()]--;
					t.pop();
				}
			}
			else{
				f[a[j]]++;
				t.push(a[j]);
			}
		}
		while(!t.empty()){
			ans[t.top()]++;
			t.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
