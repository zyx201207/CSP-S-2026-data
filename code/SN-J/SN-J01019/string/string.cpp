#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans;
	cin>>n;
	int a[1005];
	char b[1005];
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		if(a[i]!=b[n-i]){
			ans+=a[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
