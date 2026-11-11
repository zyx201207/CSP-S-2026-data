#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(maxx<a) maxx=a;
	}
	if(m==1){
		cout<<maxx;
	} 
	return 0;
}
