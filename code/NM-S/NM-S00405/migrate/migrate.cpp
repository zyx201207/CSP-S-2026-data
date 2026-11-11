#include<bits/stdc++.h> 
using namespace std;
int n,m,nn,nnn;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>nnn>>nn;
		cout<<nn+2-nnn+1<<endl;
	}
	return 0;
}
