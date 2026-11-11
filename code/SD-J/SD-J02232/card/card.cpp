#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
