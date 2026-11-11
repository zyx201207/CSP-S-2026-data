#include<bits/stdc++.h>
using namespace std;
int maxn=-1;
int n,m,b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]>maxn) maxn=b[i]; 
	}
	cout<<maxn;
	return 0;
} 

//T3
