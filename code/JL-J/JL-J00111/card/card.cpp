#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],c[300010],p[300010],m;
stack<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]){
				while(q.top()!=a[j]){
					c[q.top()]--;
					q.pop();
				}
			}
			else{
				q.push(a[j]);
				c[a[j]]++;
			}
		}
		while(q.size()){
			p[q.top()]++,c[q.top()]--,q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
}