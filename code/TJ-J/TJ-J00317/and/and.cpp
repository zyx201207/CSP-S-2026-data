#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,m,ans = 0,a[10000005];
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++){
		ans = a[i-1];
		ans = a[i]&ans;
	}cout<<ans;
	/*for(int i = 1;i<m;i++){
		if(m = 1){
			cout<<a[m];
			break;	
		}else{
			
		}
	}*/
	return 0;
}

