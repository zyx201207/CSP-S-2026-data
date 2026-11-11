#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],t[N];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int x[N]={0};
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0){
				s.push(a[j]);
				x[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					x[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			t[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
