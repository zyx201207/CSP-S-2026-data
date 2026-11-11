#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long p=1000000010;
	long long s[p];
	long long n,a;
	char c;
	cin >> n;
	long long k=0;
	for(long long i=1;i<=n;i++){
		cin >> a >> c;
		for(long long j=1;j<=a;j++){
			k++;
			s[k]=int(c); 
		}
	}
	
	long long ans=0;
	if(k%2==0){
		for(long long w=1;w<=k/2;w++){
			for(long long z=k;z>=k/2+1;z--){
				if(s[w]!=s[z]){
					ans++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	else{
		for(long long h=1;h<=k/2+1;h++){
			for(long long l=k;l>=k/2+1;l--){
				if(s[h]!=s[l]){
					ans++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
