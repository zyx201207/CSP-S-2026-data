#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n;
int ans;
long long a[MAXN];
char c[MAXN];//50
long long cntl,cntr;
long long maxa,suma;
string s=" ";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		suma+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[suma-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;

//	int l=1,r=n;
//	while(l<r){
//		while(c[l]==c[l+1]){
//			cntl+=a[l];
//			l++;
//		}
//		while(c[r]==c[r-1]){
//			cntr+=a[r];
//			r--
//		}
//		if(cntl>=cntr){
//			
//		}
//	}
//	int now=1;
//	for(int i=1;i<=n;i++){
//		if(c[i]!=c[n-i+1]){
//			if(a[i]<=a[n-i+1]){
//				ans+=a[i];
//				
//			}
//		}
//	}
}
