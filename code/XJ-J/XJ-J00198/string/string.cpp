#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],k,cnt;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		k+=a[i];
	}
	for(int i=k;i>=1;i++){
		s1[i]=s[i];
	}
	for(int i=1;i<=k/2;i++){
		if(s1[i]!=s1[k-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
