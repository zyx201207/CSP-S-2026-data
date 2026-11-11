#include <bits/stdc++.h>
using namespace std;
long long n,m,z[200002],mxq=-1;
void qwq(long long l,long long q,int k){
	if(l==0){
		if(q>mxq){
			mxq=q;
		}
		return ;
	}
	for(int i=k+1;i<=n;i++){
		qwq(l-1,q&z[i],i);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	for(int i=1;i<=n;i++){
		qwq(m-1,z[i],i);
	}
	cout<<mxq;
	return 0;
}
