#include <bits/stdc++.h>
using namespace std;
int a[2000005],m,n;
long long ans = 200000005;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}sort(a + 1,a + n + 1);
	for(int i = n - m + 1;i <= n;i++){
		if(ans > a[i]){
			ans = a[i];
		}
	}cout<<ans<<endl;
	return 0;
}
