#include <bits/stdc++.h> 
using namespace std;
long long a[1001000],book[1001000];
long long note(long long x){
	long long i,ans = 1;
	while(x != 1){
		x = x / 2;
		ans ++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,i,k;
	cin>>n>>m;
	for(i = 1;i <= n;i ++){
		cin>>a[i];
		book[a[i]] ++;
	}
	sort(a + 1,a + 1 + n);
	for(i = 1;i <= n;i ++){
		if(book[a[i]] >= m){
			k = a[i];
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
