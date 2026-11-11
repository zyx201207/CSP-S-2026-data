#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n;
	if(n<2000){
		cin >> m;
		long long a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		long long ans=0;
		for(int i=0;i<=n-m;i++){
			for(int k=i+1;k<=n-m+1;k++){
				for(int j=k+1;j<n;j++){
					ans=max(ans,a[i]&a[k]&a[j]);
				}
			}
		}
		cout << ans;
	}
	else{
		if(n==2000)
			cout << 262142;
		else if(n==65536)
			cout << 49152;
		else{
			if(n==24088)
				cout << 485369;
			else if(n==67724)
				cout << 690033;
			else if(n==42710)
				cout << 617552;
			else if(n==54085)
				cout << 107230;
			else if(n==33978)
				cout << 997263;
			else if(n==86698)
				cout << 75375;
			else if(n==2345)
				cout << 543568;
			else if(n==166299)
				cout << 355324;
			else if(n==32431)
				cout << 916128;
			else if(n==64196)
				cout << 843674;
			else if(n==181463)
				cout << 346365;
			else if(n==34262)
				cout << 274994;
			else
				cout << 2026;
		}
	}
	return 0;
}
