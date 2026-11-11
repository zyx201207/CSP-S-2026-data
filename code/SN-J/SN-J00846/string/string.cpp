#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200004];
char c[200004];
int ans=0;
signed main(){
	freopen("string.in","r",stdout);
	freopen("string.out","w",stdout);
//许子衿 SN-J00846 西安翱翔中学 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int t=s.size()-1;
	if(t&2==0){
		t/=2;
	}else{
		t=t/2+1;
	}
	int ans=0;
	for(int i=0;i<t;i++){
		if(s[i]!=s[n-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
