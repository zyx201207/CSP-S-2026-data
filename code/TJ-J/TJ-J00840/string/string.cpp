#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
bool f=1;
int n;
long long L,a[maxn],ans=0;
string s="",c[maxn];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	//cout<<s<<endl;
	for(int i=0;i<L/2;i++){
		if(s[i]!=s[L-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
