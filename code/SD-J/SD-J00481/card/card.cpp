#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
long long cnt[300010];
long long ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		stack<long long> st;
		memset(cnt,0,sizeof(cnt));
		for(int i=j;i<=n;i++){
			if(cnt[a[i]]%2==0){
				st.push(a[i]);
				cnt[a[i]]++;
			}else{
				while(st.top()!=a[i]){
					cnt[st.top()]--;
					st.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]!=0)ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
