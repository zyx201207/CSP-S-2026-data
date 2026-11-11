#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[30005],a[50005];
bool f[30005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				int q=s.top();
				while(q!=a[j]){
					f[s.top()]=0;
					s.pop();
					q=s.top();
				}
			}
			else{
				s.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!s.empty()){
			f[s.top()]=0;
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<' ';
	return 0;
} 
