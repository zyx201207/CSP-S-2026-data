#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n,a[maxn],ans;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;cin>>a[i]>>c;
		s+=c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l]>a[r]){
			if(s[l]!=s[r]) ans+=a[r];
			a[l]-=a[r],r--;
		}else if(a[l]<a[r]){
			if(s[l]!=s[r]) ans+=a[l];
			a[r]-=a[l],l++;
		}else{
			if(s[l]!=s[r]) ans+=a[l];
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
/*
By ZJ-J00357.
Luogu UID:1086453.
*/