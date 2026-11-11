#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=5*1e5+10;
int a[N],cha[N];
long long b[N];
long long c[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool tepanA=true;
	bool tepanB=true;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) {
			tepanA=false;
		}
	}
	//cout<<cha[1]<<cha[2]<<cha[3]<<cha[4]<<cha[5];
	sort(a+1,a+n+1);
	
	b[1]=a[1];
	for(int i=2; i<=n+1; i++) {
		b[i]=a[i]+b[i-1];
		//cout<<b[i];
	}
	//tabanA

	bool guo=false;
	for(int i=1; i<=n; i++) {
		if(a[i]!=i) {
			tepanA=false;
			break;
		}
	}
	
	
	for(int i=2; i<=n; i++) {
		if(abs(a[i]-a[i-1])!=abs(a[i+1]-a[i])){
			tepanB=false;
			break;
		}
	}
	if(m>b[n]){
		cout<<n;
		return 0;
	}
	if(tepanA) {

		for(int i=1; i<=n; i++) {
			if(b[i]>m) {
				cout<<i;
				return 0;
				break;
			}
		}

	} 
	return 0;
}
