#include<bits/stdc++.h>
using namespace std;
int tong[500005];
int tong1[500005];
stack<int> s;
int n,m;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty()) s.pop();
		for(int j=i;j<=n;j++){
			if(tong[a[j]]==1){
				while(s.top()!=a[j]){
					tong[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				tong[a[j]]++;
			}
		}
		for(int i=1;i<=n;i++){
			tong1[i]+=tong[i];
			tong[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong1[i]<<" ";
	}
	return 0;
}