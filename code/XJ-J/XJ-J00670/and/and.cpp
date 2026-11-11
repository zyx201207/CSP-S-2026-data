#include<bits/stdc++.h>
using namespace std;
long long T,maxa=-1;
long long a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> T;
	for(long long i=0;i<=T;i++){
		cin >> a[i];
	}
	for(long long i=1;i<=T;i++){
		maxa=max(a[i-1]&a[i],maxa);
	}
	cout << maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}