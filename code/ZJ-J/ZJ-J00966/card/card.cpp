#include <bits/stdc++.h>
using namespace std;

int a[500005],f[300005],ans[300005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(s.top()!=a[j]){
					f[s.top()]--;
					ans[s.top()]--;
					s.pop();
				}
				f[s.top()]--;
				ans[s.top()]--;
				s.pop();
			}
			f[a[j]]++;
			ans[a[j]]++;
			s.push(a[j]);
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
