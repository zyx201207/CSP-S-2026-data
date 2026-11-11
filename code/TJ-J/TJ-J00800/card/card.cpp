#include<bits/stdc++.h>
using namespace std; 
stack<int> s;
int a[200010],ans[300010],k[300010],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			k[a[j]]++;
			if(k[a[j]]==2){
				k[s.top()]--;
				s.pop();
				while(s.top()!=a[j]){
					k[s.top()]--;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
		for(int j=1;j<=m;j++) k[j]=0;
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
