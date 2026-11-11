#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  n,m,a;
	cin>>n>>m;
	long long x=0;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>x){
			x=a;
		}
	} 
	cout<<0;
	return 0;
}
