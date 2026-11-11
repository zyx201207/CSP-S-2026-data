#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,num=0;
	long long a[2010];
	string c[2010],s;
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		num+=a[i];
	}
	
	if(n<=2000){
		
		for(long long i=1;i<=n;i++){
			while(a[i]--){
				s+=c[i];
			}
		}
		long long l=0,r=num-1;
		
		if(num%2==1){
			while(l!=num/2){
				if(s[l]!=s[r]){
					sum++;
					l++;
					r--;
				}
				else{
					l++;
					r--;
				}
			}
		}
		else{
			while(l<=num/2-1 && r>=num/2){
				if(s[l]!=s[r]){
					sum++;
					l++;
					r--;
				}
				else{
					l++;
					r--;
				}
			}
		}
		cout << sum;
	}
	return 0;
}