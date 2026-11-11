#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N	=500010;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

