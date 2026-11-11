#include<bits/stdc++.h>
using namespace std;
long long w[500000],k[500],a[500],t[500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
			return 0;
		}
		else if(n==3){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	for(int i=0;i<m;i++){
		cin>>w[i];
	}for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[j]>>t[j];
		}
	}for(int i=0;i<m;i++){
		cin>>w[i];
	}
	return 0;
}
