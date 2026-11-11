#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		
	int n,m;
	cin>>n>>m;
	int a[100];
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	cout<<n<<m;
	for(int i=0;i<=n-1;i++){
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
