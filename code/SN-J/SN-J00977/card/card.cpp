#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,a[20005];
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]<a[n-1]){
		cout<<a[n-1]<<a[n-2]<<a[n-3];
	}
	else{
		cout<<m<<n<<a[0];
	}
	return 0;
}
