#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[300005];
int ans[300005];
struct ee{
	int f;
	int s;
	
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool bj=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1])bj=1;
	}
	if(n<=5000){
		for(int i=n;i>0;i--){
			vector<int> st;
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]==0){
					cnt[a[j]]=1;
					st.push_back(a[j]);
				}
				else {
					while(st[st.size()-1]!=a[j]){
						cnt[st[st.size()-1]]=0;
						st.pop_back();
					}
				}
			}
			for(int i=0;i<st.size();i++){
				ans[st[i]]++;
				cnt[st[i]]=0;
			}
			st.clear();
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	else {
		if(m==1){
			cout<<n;
			return 0;
		}
		if(m==2){
			ans[a[n]]++;
			if(a[n]!=a[n-1]){
				ans[a[n]]++;
				ans[a[n-1]]++;
			}
			if(a[n]==a[n-1]&&a[n]==a[n-2]){
				ans[a[n]]+=n-2;
			}
			if(a[n]!=a[n-1]&&a[n]==a[n-2]){
				ans[a[n]]+=n-2;
			}
			if(a[n]!=a[n-1]&&a[n]!=a[n-2]){
				ans[a[n]]+=n-2;
				ans[a[n-1]]+=n-2;
			}
			for(int i=1;i<=2;i++){
				cout<<ans[i]<<' ';
			}
			return 0;
		}
		else if(bj==0){
			int sum[300005]={};
			for(int i=n;i>0;i--){
				sum[a[i]]++;
			}
			for(int i=1;i<=n;i++){
				ans[i]=ans[i-1]+sum[i];
				cout<<ans[i]<<' ';
			}
		}
	}
}
