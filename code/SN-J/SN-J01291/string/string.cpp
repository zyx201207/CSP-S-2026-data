#include<bits/stdc++.h>
using namespace std;
int a[100000005],n,ans = 0;
string q;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++){
		cin >> a[i] >> q[i];
		while (q[i] = q[1]){
			if(q[i] == q[1]){
				if(q[i-1] == q[1]){
					ans += 0;
				}
				else{
					q[i-1] = q[1];
					ans += 1;
				}
			}
			else{
				q[i] = q[1];
				ans += 1;
				if(q[i-1] == q[1]){
					ans += 0;
				}
				else{
					q[i-1] = q[1];
					ans += 1;
				}
			}
		}
	}
	cout << ans-1;
	return 0;
}
