#include<bits/stdc++.h>
using namespace std;
const int N=200001;
long long n,m,a[N],mannum,q;
void ands(long long node,long long num,long long k){
	if(k==0){
		mannum=max(mannum,num);
		return;
	}
	for(int i=node;i<n;i++){
		q=num&a[i+1];
		ands(i+1,q,k-1);
	}
	return;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n-m+1;i++){
		ands(i,a[i],m-1);
	}
	cout<<mannum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
