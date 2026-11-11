#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
string s;
char c[N];
int n,a[N],ans,len;
signed main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=1,r=n,cl=a[1],cr=a[n],sy=a[l],syr=0;
	char syc;
	while (l<=r){
		if (c[l]==c[r]){
			if (sy>a[r]){
				sy-=a[r];
				r--;
			}
			else {
				sy=a[r]-sy;
				l++;
			}
		}
		else {
			if (sy>a[r]){
				ans+=a[r];
				sy-=a[r];
				r--;
			}
			else {
				ans+=sy;
				sy=a[r]-sy;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
string s;
char c[N];
int n,a[N],ans,len;
signed main(){

	cin>>n;
	if (n==1){
		cout<<0;
		return 0;
	}
	s+='0';
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l=s.size();
	for (int i=1;i<=l/2;i++){
		if (s[i]!=s[l-i]){
			ans++;
		}
	}
	cout<<ans;
	/*
	int f=0,b=0;
	for (int i=1;i<=n/2;i++){
		f+=
	}*
	return 0;
} 

*/






//yiciweijie


























































