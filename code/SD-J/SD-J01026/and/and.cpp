#include<bits/stdc++.h>
using namespace std;
long long a[200005],maxn=0; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
		maxn=a[i];}
	}
	if(m==1){
		cout<<maxn;
	}
	return 0;
} 

