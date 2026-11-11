#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int l = 1,r = n;
	while(l < r){
		int mi = min(a[l],a[r]);
		if(c[l] == c[r]){
			a[l] -= mi;
			a[r] -= mi;
		}else{
			ans += mi;
			a[l] -= mi;
			a[r] -= mi;
			
		}
		if(a[l] == 0){
			l++;
		}
		if(a[r] == 0){
			r--;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
