#include<bits/stdc++.h>
using namespace std;
long long n,a,ii,ans;
char aa[1000000005];
char c; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			ii++;
			aa[ii]=c;
		}
	}
//	for(int i=1;i<=ii;i++){
//		cout<<aa[i];
//	}
//	cout<<" ";
	for(int i=1;i<=ii/2;i++){
//		cout<<aa[i]<<" "<<aa[ii-i+1]<<"\n";
		if(aa[i]!=aa[ii-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}

