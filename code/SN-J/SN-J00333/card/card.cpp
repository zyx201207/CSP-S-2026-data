#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,x;
int a[500005],b[500005];
bool c[500005];
stack<int>s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=m;k++){
		for(int i=k;i<=n;i++){
			s.push(a[i]);
		}
		while(!s.empty()){
			x++;
			b[x]=s.top();
			if(s.top()==k){
				ans++;
			}
			s.pop();
		}	
		for(int j=x;j>=1;j--){
			s.push(b[j]);
		}
		cout<<ans<<' ';
		ans=0;
	}
	return 0;
}
