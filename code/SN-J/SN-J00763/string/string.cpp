//SN-J00763 西安交通大学附属中学 胡妍馨
#include<bits/stdc++.h>
using namespace std;
long long n,m,t;
long long ans;
string s;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		t+=a;
		for(int j=0;j<a;j++){
			s=s+c;
		}
	}
	if(t%2==0) m=t/2;
	else m=t/2+1;//3
	for(int i=0;i<m;i++){
		if(s[m+m-i-2]!=s[i]){  // a a a a a
			ans++;             // 0 1 2 3 4
		}
	}
	cout<<ans;
	return 0;
} 
