#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long A[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>A[i];
	}
	sort(A + 1,A + n + 1);
	ans = A[n];
	m--;
	for(int i = n - 1;i >= 1;i--){
		if(m == 0) break;
		ans = ans & A[i];
		m--;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
