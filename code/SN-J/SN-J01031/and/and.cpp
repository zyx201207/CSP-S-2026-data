#include <bits/stdc++.h>
using namespace std;
long long read(){
	int ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10+ch-'0';
		ch = getchar();
	}
	return ans*f;
}
const int N = 2e5 + 10;
long long n,m,cnt,ans;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read(),m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+n+1);
	ans = a[n];
	for(int i=n-1;i>=1;i--){
		if(cnt==m) break;
		ans &= a[i];
		cnt++;
	}
	cout<<ans;
	
	
	return 0;
}
//aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa aaaaa
