#include <bits/stdc++.h>
using namespace std;
long long a[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char c;
	cin>>n;
	long long k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		a[i]+=k;
		for(int j=k;j<=a[i];j++){
			s[j]=c;
		}
		k=a[i];
	}
	int ans=0;
	for(int i=1;i<=k/2;i++){
		if(s[k+1-i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
