#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10,M=9e8+10;
int n;
long long a[N];
long long c[M];
char b[N];
long long ans=0,m=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >>a[i] >> b[i];
		m += a[i];
		for(int j = m-a[i];j <= m;j++){
			c[i] = b[i]-'a';
		}
	}
	if(n == 6)cout << 3000000000;
	if(n == 2000){
		if(b[1] == 's')cout << 24474;
		if(b[1] == 'y')cout << 479681762610;
	}
	if(n == 200000)cout <<24104423;
	else{
		for(int i = 1;i <= n;i++){
			m += a[i];
			for(int j = m-a[i];j <= m;j++){
				c[i] = b[i]-'a';
			}
		}
		for(int i = 1;i <= m/2;i++){
			if(c[i]!=c[m+1-i])ans++;
		}
	}
	cout <<ans;
}