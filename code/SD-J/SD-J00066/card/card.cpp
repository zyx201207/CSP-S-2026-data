#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005],ans[300005];
bool vis[300005],car[300005];
int n,m,flag;
stack <int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				int xxx=flag;
				for(int k=xxx;k>=cnt[a[j]];k--){
					int t=st.top();
					st.pop();
					vis[t]=0;
					cnt[t]=0;
					flag--;
				}
				st.push(a[j]);
				flag++;
				cnt[a[j]]=flag;
			}
			else{
				st.push(a[j]);
				vis[a[j]]=1;
				cnt[a[j]]=j-i+1;
				flag++;
			}
		}
		cout<<"fay";
		for(int j=1;j<=flag;j++){
			int t=st.top();
			st.pop();
			car[t]=1;
		}
		for(int j=1;j<=m;j++){
			if(car[j]){
				ans[j]++;
			}
		}
		for(int j=1;j<=m;j++){
			vis[j]=0;
			cnt[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
