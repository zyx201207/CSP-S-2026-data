#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n;
char c[N];
long long a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	
	long long pre=0,suf=0,ans=0;
	
	for(int i=1,j=n;i<=n&&i<j;i++){
		pre += a[i];
		while(pre>suf&&i<j){
			long long temp = a[j];
			if(suf+a[j]>pre) temp = pre-suf;
			
			if(c[j]!=c[i]) ans += temp;
			
			if(suf+a[j]<=pre) j--;
			else a[j] -= temp;
			
			suf += temp;
		}
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;

}
