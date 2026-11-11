#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int num[101];
	cin>>n>>m;
	for(int i=1;i<=m){
		cin>>num[i];
	}
	for(int i=1;i<=3;i++){
		cout<<num[m-2+n+4-i];
	}
}
