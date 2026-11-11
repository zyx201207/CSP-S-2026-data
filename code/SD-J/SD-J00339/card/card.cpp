#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500010],cnt[500010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> p;
		int f[500010]={0};
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(p.top()==a[i]){
					p.pop();
				}
			}else{
				p.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i]){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
