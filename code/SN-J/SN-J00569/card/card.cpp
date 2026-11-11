freopen("card.in","r",stdin)
freopen("card.out","w",stdout)
#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m,ans[300000],M[500000];
f(int x){
	for(int i=1;i<=n;i++){
		if(q[i]==x){
			return 1;
			break;
		}
		else{
			return 0;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>M[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(M[j])){
				q.push(M[j]);
			}else{
				while(q.end()!=M[j]){
					q.pop(q.end());
				}
			}
		}
		for(int j=1;j<=q.size();j++){
			ans[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
