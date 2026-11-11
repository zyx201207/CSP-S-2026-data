#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int c[n];
	int t[m];
	for(int i=0;i<n;i++){
		cin>>c[i];
		t[c[i]]++;
	}
	for(int i=0;i<m;i++){
		cout<<t[m]<<" ";
	}
	return 0;
}
