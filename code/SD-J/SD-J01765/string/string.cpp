#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,s,s1,ans1,ans2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c;
	cin>>n;
	c+=" ";
	for(int i=1;i<=n;i++){
		char f;
		cin>>a>>f;
		s+=a;
		while(a--){
			c+=f;
		}
		
	}
	for(int i=1;i<=(s+1)/2;i++){
		if(c[i]!=c[s+1-i]){
			ans1++;
		}
	}
	cout<<ans1;
} 


