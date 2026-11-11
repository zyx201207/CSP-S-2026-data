//分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++;
#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=300) {
		string s;
		int a;
		char c;
		for(int i=1; i<=n; i++) {
			cin>>a>>c;
			sum+=a;
			for(int j=1; j<=a; j++) {
				s+=c;
			}
		}
		for(int i=0; i<sum/2; i++) {
			if(s[i]!=s[sum-i-1]) {
				ans++;
			}
		}
		cout<<ans;
	} else {
		int a[200001];
		char c[200001];
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>c[i];
		}
		for(int i=1; i<=n/2; i++) {
			if(c[i]!=c[n-i+1]) {
				if(a[i]>a[n-i+1]) {
					ans+=a[n-i+1];
					if(c[n-i]==c[i]) {
						a[n-i]=a[n-i]-a[i]+a[n-i+1];
					}
				} else if(a[i]<a[n-i+1]) {
					ans+=a[i];
					if(c[n-i+1]==c[i+1]) {
						a[i+1]=a[i+1]+a[i]-a[n-i+1];
					}
				} else ans+=a[i];
			} else {
				if(a[i]>a[n-i+1]) {
					if(c[n-i]==c[i]) {
						a[n-i]=a[n-i]-a[i]+a[n-i+1];
					} else if(c[n-i]!=c[i]) {
						ans+=a[i]-a[n-i+1];
						a[n-i]=a[n-i]-a[i]+a[n-i+1];
					}
				} else if(a[i]<a[n-i+1]) {
					if(c[n-i+1]==c[i+1]) {
						a[i+1]=a[i+1]+a[i]-a[n-i+1];
					} else if(c[n-i]!=c[i]) {
						a[i+1]=a[i+1]+a[i]-a[n-i+1];
						ans+=a[n-i+1]-a[i];

					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}

//分数++;  分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++;
