#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int a[N],b[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k,c=1e6;
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i];
			int q=b[i]-a[i];
			c=min(c,q);
		}
		cout << t << endl;
	}
	return 0;
} 
