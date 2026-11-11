#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=10000000010;

bool cmp(long long a,long long b){
	if(a>=b){
		return 1;
	}
	return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	vector<long long>a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<m;i++){
		if(ans>a[i]){
			ans=a[i];
		}
	}
	cout << ans << endl;
	return 0;
} 
