#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	string s;
	long long n,w,z=0,l=1,ans=0;
	cin>>n;
	int r=n;
	for(int i=1;i<=n;i++){
	cin>>w;
	for(int j=1;j<=w;j++){
    z++;
	cin>>s[z];
	}
	}
	for(int i=1;i<=s.size()/2;i++){
        if(s[r]!=s[l]){
            ans++;
        r--;
        l++;
	}
	}
	cout<<ans;
    return 0;
}
