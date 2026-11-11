#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int n,m,a[N],c[N];
bool f[N];
void maind(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s; 
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=1;
				s.push(a[j]);
			}
			else{
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		maind();
	}
	return 0;
}

