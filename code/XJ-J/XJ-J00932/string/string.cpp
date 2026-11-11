#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
	freopen("string.in","r",atdin)
	freout("string.out","r",atdin);
	int n;
	int m;
	char c;
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin >> m >>c;
		for(int j=1;j<=i+1;j++){
			m+=c;	
		}
	}
	return 0;
}
		