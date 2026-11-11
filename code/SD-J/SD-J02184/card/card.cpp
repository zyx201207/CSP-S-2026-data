#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		unordered_map<int,int>mp;
		stack<int>s;
		for(int j=i;j<n;j++){
			if(mp[a[j]]==1){
				while(s.top()!=a[j]&&!s.empty()){
					mp[s.top()]--;
					s.pop();
				}
			}
			else {
				s.push(a[j]);
				mp[a[j]]++;
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
} 
