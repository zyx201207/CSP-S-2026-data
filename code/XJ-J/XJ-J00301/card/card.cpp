#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	int n,m,a,b=0,s;
	cin>>n>>m;
	s=0;
	for(int i=0;i<=n;i++){
		cin>>a;
		b=a;
		if(a==b)cout<<a+b+n;
		else a+=b;
	}
	
	return 0;
}