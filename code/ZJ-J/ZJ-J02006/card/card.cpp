#include<bits/stdc++.h>
using namespace std;
int n,m,a[501000],m2[30010];
map<int,int> mp;
stack<int> p[501000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		mp.clear();
		
		for(int j=i;j<=n;j++){
			p[i].push(a[j]);
			mp[a[j]]++;
			if(mp[a[j]]==2){
				mp[a[j]]--;
				p[i].pop();
				while(p[i].top()!=a[j]){
					mp[p[i].top()]--;
					p[i].pop();
					
				}
			}
			
		}
		
		while(!p[i].empty()){
			m2[p[i].top()]++;
			p[i].pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<m2[i]<<" ";
	}
	return 0;
}
