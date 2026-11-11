#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],f;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	for(int i=1,j=n;i<=n,j>=1;i++,j++){
		if(s[i]==s[j]&&f==0){
			f=0;
		}
		else{
			f=1;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}
//	else{
//		
//	}
	return 0;
} 

