#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long w[5000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}for(int i=0;i<n;i++){
		cout<<w[i];
	}
	return 0;
} 
