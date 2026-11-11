#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200006] = {};
	char c[200006] = {};
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
	}
	int i = 1,j = n;
	long long ans = 0;
	while(i < j){
		if(c[i] != c[j]){
			if(a[i] < a[j]){
				ans += a[i];
				a[j] = a[j] - a[i];
				i++;
			}else{
				ans += a[j];
				a[i] = a[i] - a[j];
				j--;
			}
		}else{
			if(a[i] < a[j]){
				a[j] = a[j] - a[i];
				i++;
			}else{
				a[i] = a[i] - a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
