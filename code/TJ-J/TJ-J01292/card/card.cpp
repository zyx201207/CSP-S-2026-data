#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long i=0,j,n,m,cnt=0,T,k,c=0,l,a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(a[i]==a[i-1]){
			c++;
		}else{
			cout<<c<<' ';
			c=0;
		}
	}
	return 0;
}
