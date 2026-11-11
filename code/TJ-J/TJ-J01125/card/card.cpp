#include<bits/stdc++.h>
using namespace std;const int N=5e5+5;
int n,m,a[N],f[N],ans[N],b=1;stack<int>s;
int main(){freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!f[a[j]])s.push(a[j]),f[a[j]]=1;
			else while(s.top()!=a[j])f[s.top()]=0,s.pop();
		}while(s.size())ans[s.top()]++,f[s.top()]=0,s.pop();	
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
