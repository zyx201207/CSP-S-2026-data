#include<bits/stdc++.h>
using namespace std;
long long a[10000091],c=-1,m,n;
void ccc(long long t,int s,int i){
	if(s==m){
		c=max(c,t);
	}
	else{
		for(int k=i+1;k<=n;k++){
			ccc((t&a[k]),s+1,k);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ccc(a[i],1,i);
	}
	cout<<c;
	return 0;
}