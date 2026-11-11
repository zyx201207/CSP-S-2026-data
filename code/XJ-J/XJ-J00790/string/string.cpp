#include<bits/stdc++.h>
using namespace std;

long long a[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long ans = 0;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
		if(a[i]-a[i-1]!=1){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}