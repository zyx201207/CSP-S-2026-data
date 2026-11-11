#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int l=1,r=n,al=a[1],ar=a[n],amin;
	while(l<=r){
		amin=min(al,ar);
		if(c[l]!=c[r])ans+=amin;
		al-=amin;
		ar-=amin;
		if(al==0){
			l++;
			al=a[l];
		}
		if(ar==0){
			r--;
			ar=a[r];
		}
	}
	cout << ans;
	return 0;
}
