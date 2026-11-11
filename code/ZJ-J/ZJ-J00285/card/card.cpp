#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500010];
int ans[300010];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		int sum[300010];
		for(int j=1;j<=m;j++) sum[j]=0;
		for(int i=k;i<=n;i++){
			if(!sum[a[i]]){
				s.push(a[i]);
				sum[a[i]]++;
			}
			else{
				while(s.top()!=a[i]&&!s.empty()){
					sum[s.top()]--;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

