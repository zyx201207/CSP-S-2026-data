#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int n,m,a[500005],num[300005],ans[300005];
bool vis[500005],check=1;
stack<int> st;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])check=0;
	}
	if(check){
		for(int i=1;i<=n;i++){
			num[a[i]]++;
			ans[a[i]]=n;
		}
		for(int i=2;i<=n;i++){
			num[a[i-1]]--;
			if(num[a[i-1]]==0)ans[a[i-1]]-=(n-i+1);
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					vis[a[j]]=1;
					st.push(a[j]);
				}
				else {
					while(1){
						int x=st.top();
						st.pop();
						if(x==a[j])break;
						vis[x]=0;
					}
					st.push(a[j]);
				}
			}
			for(int i=1;i<=m;i++){
				if(vis[i])num[i]++;
				vis[i]=0;
			}
		}
		for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	}
	return 0;
}
