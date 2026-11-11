#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int n;
int cnt=0;
string str,ans;
int a[200005];
//int a1[200005];
char c[200005];
//char c1[200005];
signed main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
//	for(int i=0;i<n;i++){
//		a1[i]+=a[n-i-1];
//	}
//	for(int i=0;i<n;i++){
//		c1[i]+=c[n-i-1];
//	}
//	for(int i=0;i<n;i++){
//		if(c[i]!=c1[i]) cnt+=max(a[i],a1[i]);
//	}
//	cout<<cnt/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			str+=c[i];
		}
	}
	for(int i=str.length()-1;i>=0;i--){
		ans+=str[i];
	}
	int cnt=0;
	for(int i=0;i<ans.length();i++){
		if(ans[i]!=str[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
} 
