#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
char s[200005];
long long len=0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	long long l=1,r=n, cnt1=0, cnt2=0, ans=0;
	for(int i=1;i<=len/2;i++){
		cnt1++;
		cnt2++;
		if(s[l]!=s[r])ans++;
		if(cnt1==a[l]){
			l++;
			cnt1=0;
		}
		if(cnt2==a[r]){
			r--;
			cnt2=0;
		}
	}
	cout<<ans;
	return 0;
} 

