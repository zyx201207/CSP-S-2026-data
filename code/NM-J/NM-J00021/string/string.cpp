#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	string a;
	for(long long i=0;i<n;i++){
		long long x;
		char s;
		cin>>x>>s;
		while (x--) a.push_back(s);
	}
	for(long long i=0,j=a.size()-1;i<a.size()-1;i++){
		if(j!=i&&a[i]!=a[j]){
			a[j]=a[i];
			ans++;
		}
		if(j==i) break;
		j--;
	}
	cout<<ans;
	return 0;
}
