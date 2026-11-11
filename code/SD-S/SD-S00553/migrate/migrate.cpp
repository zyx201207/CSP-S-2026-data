#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int c,t;
int n,d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int sum=a[2]-a[1];
		if(sum==d) cout << 0;
		else{
			int cnt=d/sum+1;
			cout << n-cnt;
		}
		cout << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
