#include <bits/stdc++.h>
using namespace std;
int n,m,team[100000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>team[i];
	}
	for(int i=1;i<=m;i++){
		cout<<m-i;
	}
	return 0;
}
