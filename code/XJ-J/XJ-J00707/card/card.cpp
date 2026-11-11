#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin)
	freopen("card.out","w",stbout)
	int n,m,a[100];
	cin>>n>>m;
	for(int i=1;i<n;i++){
		if(a[i]==n){
			cout<<m;
		}
		else if(a[i]==m){
			cout<<n;
		}
	}
	return 0;
}