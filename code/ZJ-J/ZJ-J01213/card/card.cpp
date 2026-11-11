#include <bits/stdc++.h>
using namespace std;
int n,m;
stack <int> a;
int s[500010],f[300010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!f[s[j]]){
				a.push(s[j]);
				f[s[j]]=1;
			}
			else{
				while(a.top()!=s[j]){
					f[a.top()]=0;
					a.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i]){
				d[i]++;
				f[i]=0;
			}
		}
		while(!a.empty()) a.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
