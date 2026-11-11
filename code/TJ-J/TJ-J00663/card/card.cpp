#include <bits/stdc++.h>
using namespace std;
int card[1000005],fr[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string a,b;
	cin >> n >> m;
	for(int j=1;j<=n;j++){
		cout << a;
		b+=a;
	}
	long long len=b.size();
	for(int k=0;k<len;++k){
		for(int i=0;i<m;++i){
			cout << fr[i] << ' ';
		}	
	}
	
	return 0;
}
