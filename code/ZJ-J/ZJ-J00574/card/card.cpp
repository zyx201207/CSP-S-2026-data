#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int ans[M];
int flag[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			flag[j]=0;
		}
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(!flag[a[j]]){
				st.push(a[j]);
				flag[a[j]]++;;
			}
			else{
				while(!st.empty()){
					int x=st.top();
					st.pop();
					flag[x]--;
					if(x==a[j]){
						break;
					}
				}
				st.push(a[j]);
				flag[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(flag[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
