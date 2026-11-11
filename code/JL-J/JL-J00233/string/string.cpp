#include<bits/stdc++.h>
using namespace std;
long long n,shu[1000000],a[1000000],sum;
char zimu[1000000];
string pinjie;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shu[i]>>zimu[i];
		sum+=shu[i];
		for(int j=1;j<=shu[i];j++){
			pinjie+=zimu[i];
		}
	}
	cout<<shu[2];
	
	return 0;
}
