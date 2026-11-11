#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num[200001];
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>num[i];
	}
	cout<<num[m];
}
