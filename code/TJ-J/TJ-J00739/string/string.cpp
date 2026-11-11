#include<iostream>
using namespace std;
int n;
long long ans,l,x;
char y;
char c[5000005];
int main(){
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		cin >> x >> y;
		for(long long j = 0;j < x;j++){
			c[l] = y;
			l++;
		}
	}
	for(long long i = 0;i < l / 2;i++){
		if(c[i] != c[l - 1 - i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
