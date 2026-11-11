#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,ans1,ans=-1;
char b[200005];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){	
			s+=b[i];
		}
	}
	for(int j=l-1;j>=0;j--){
		int i;
		s1[i++]=s[j];
	}	
	for(int i=0;i<=l;i++){
		if(s[i]==s1[i+1])
			ans++;
	}
	cout<<l-ans;
	return 0;
}