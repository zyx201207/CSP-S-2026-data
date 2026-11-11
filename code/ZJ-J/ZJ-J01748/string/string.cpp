#include <bits/stdc++.h>
using namespace std;
long long n,cnt[10000005],ans;
struct qjjnb{
	long long h;
	char c;
} a[10000005];
string s1,s2;
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].h>>a[i].c;
		cnt[i]=cnt[i-1]+a[i].h;
	}
	for (int i=1;i<=n;i++){
		for (int j=cnt[i-1];j<=cnt[i]-1;j++){
			s1[j]=a[i].c;
		}
	}
	for (int i=cnt[n]-1;i>=0;i--){
		s2[n-i+1]=s1[i];
		s2[n-i+1]=s1[i];
	}
	for (int i=0;i<=cnt[n]/2-1;i++){
		if (s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
