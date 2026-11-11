#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
stack <int> s;
bool b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			
			if(b[a[j]]){
				while(s.top()!=a[j]){
					b[s.top()]=false;
					s.pop();
				}
			}else{
				s.push(a[j]);
			}
			b[a[j]]=true;
		}
		while(!s.empty()){
			s.pop();
		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				ans[j]++;
			}
			b[j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
