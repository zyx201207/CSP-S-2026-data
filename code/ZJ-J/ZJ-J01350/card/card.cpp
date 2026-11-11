#include<bits/stdc++.h>
using namespace std;
int n,m,c[300005],a[500005];
bool d[300005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[j]=0;
		}
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			if(d[a[j]]){
				s.pop();
				while(s.top()!=a[j]){
					d[s.top()]=0;
					s.pop();
				}
			}
			d[a[j]]=true;
		}
		int j=0;
		while(!s.empty()){
			j++;
			c[s.top()]++;
			s.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}