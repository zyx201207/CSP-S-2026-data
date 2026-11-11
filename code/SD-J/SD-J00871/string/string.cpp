#include<bits/stdc++.h>
using namespace std;
struct abc{
	int x;
	char c;
}a[200010];
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].c;
		}
	}
	long long ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			s[i]=s[s.size()-i-1];
			ans++;
		}
	}
	cout<<ans<<endl;
//	int l=0;int r=n;
//	while(l<=r){
//		
//	}
	return 0;
}

