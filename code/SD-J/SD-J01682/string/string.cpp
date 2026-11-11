#include <bits/stdc++.h>
using namespace std;
char a[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m = 1,num = 0,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		num += x;
		char v;
		cin>>v;
		for(int j = 1;j <= x;j++){
			a[m] = v;
			m++;			
		}
	}if(num % 2 == 0){
		int mid = num / 2;
		for(int i = 1;i <= mid;i++){
			if(a[mid - i + 1] != a[mid + i]){
				ans++;
			}
		}
	}else{
		int mid = num / 2;
		for(int i = 1;i <= mid;i++){
			if(a[mid - i + 1] != a[mid + i + 1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
