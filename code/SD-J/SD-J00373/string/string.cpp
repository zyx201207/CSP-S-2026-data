#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
string s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n;i<=j;){
		int t=min(a[i],a[j]);
		if(s[i]!=s[j]){
			if(a[i]>a[j]){
				a[i]-=t;
				j--;
				ans+=t;
			}
			else if(a[i]<a[j]){
				a[j]-=t;
				i++;
				ans+=t;
			}
			else {
				i++;j--;
				ans+=t;
			}
		}
		else {
			if(a[i]>a[j]){
				a[i]-=t;
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=t;
				i++;
			}
			else {
				i++;j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
2
2 a
3 a
*/
