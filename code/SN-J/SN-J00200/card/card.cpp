#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","cin",stdin);
	freopen("card.out","cout",stdout);
	int n,m;
	cin>>n>>m;
	int q[n];
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	cout<<q[m]<<" "<<q[n-2];
	return 0
}
 
