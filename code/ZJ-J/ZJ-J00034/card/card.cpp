#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+5],t[n+5];
	bool f[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=false;
		t[i]=0;
	}
	
	for(int i=1;i<=n;i++){	
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=true;
				s.push(a[j]);
			}
			else {
				while(s.top()!=a[j]){
					f[s.top()]=false;
					s.pop();
				}
				f[s.top()]=false;
				s.pop();
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]){
				t[j]++;
			}
		}
	 	
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}