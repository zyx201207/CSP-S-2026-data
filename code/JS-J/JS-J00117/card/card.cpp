#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],s[M];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int>st;
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0)while(st.top()!=a[j])f[st.top()]=0,st.pop();
			else{
				f[a[j]]=1;
				st.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++)if(f[j])s[j]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
