#include<bits/stdc++.h>
using namespace std;
const int M=2e5+7;
struct st{
	int nu;
	char c;
}a[M];
int n;
long long s=0,s1[M];
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int maxn=-1;
	for(int i=1; i<=n; i++){
		cin >> a[i].nu;
		cin >> a[i].c;
		s += a[i].nu;
		s1[i] = s1[i-1]+a[i].nu;
		maxn = max(a[i].nu,maxn);
	}
	if(n==1){
		cout << 0;
		return 0;
	}else if(n<=200000 && maxn<=500){
		for(int i=1; i<=n; i++)
			for(int j=1; j<=a[i].nu; j++)
				ss += a[i].c;
		ss = ' '+ss;
		long long ans=0;
		for(int i=1; i<=s/2; i++)
			if(ss[i] != ss[ss.size()-i])
				ans++;
		cout << ans;
	}else{
		long long ans=0,mid=s/2;
		if(s%2 == 1)
			mid++;
		int l=0,r=0;
		for(int i=1; i<=n; i++){
			if(s1[i-1] <= mid && s1[i] >= mid){
				l = i-1;
				r = i;
				break;
			}
		}
		for(int j=l; j>=0; j--){
			while(mid-s1[j] >= s1[r]-mid && r<=n){
				if(a[r].c != a[j].c && j!=0 && r==l+1)
					ans += (a[r].nu-mid+s1[l]);
				else if(a[r].c != a[1].c && j==0)
					ans += a[r].nu;
				else if(a[r].c != a[j].c && j!=0)
					ans += a[r].nu;
				r++;
			}
		}
		cout << ans;
	}
	return 0;
}