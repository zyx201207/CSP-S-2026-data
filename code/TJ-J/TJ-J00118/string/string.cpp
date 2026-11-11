#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string hh;
	int sum=0;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		sum+=m;
		for(int j=1;j<=m;j++){
			char a;
			cin>>a;
			hh[i*j]+=a;
		}
	}
	for(int i=1;i<=sum;i++){
			cout<<hh[i];
		}
	
	 
	cout<<'0';
	return 0;
}
