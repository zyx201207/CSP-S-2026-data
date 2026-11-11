#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=200005;
long long a[N];
char c[N];
long long n,len=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int l=0,r=len-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
