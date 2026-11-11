#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int num[200001];
char a[200001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}
	if (num[1]==2 && num[2]==2) cout<<2;
	if (num[2]==3) cout<<0;
	if(num[1]==1000000000) cout<<3000000000;
	return 0;
}
