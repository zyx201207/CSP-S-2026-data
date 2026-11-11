#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long b[100001]={};
	for(int i=1;i<=n;i++){
    cin>>a[i];
 }
 long long l=a[n],v=a[1];
 
 b[l]=n;
 b[v]=m;
for(int j=2;j<=n-1;j++){
	int y=a[j];
	if(y!=v&&y!=l){
	b[y]=n/m;}
}
for(int k=1;k<=m;k++){
	cout<<b[k]<<" ";
}
	return 0;
} 
