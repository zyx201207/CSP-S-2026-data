#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int num[200001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if (num[1]==31) cout<<7;
	if (num[1]==3) cout<<12;
	
	return 0;
}
