#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		int n,d;
		cin>>n>>d;
		if (n==1){
			cout<<1;
		}
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (a[2]-a[1]==a[3]-a[2]){
			if (d<a[1]){
				cout<<0;
			} else {
				if(a[n]%d==0){
					cout<<a[n]/d;
				} else {
					cout<<a[n]/d;
				}
			}
		} else {
			cout<<1;
		}
	}
	return 0;
}





