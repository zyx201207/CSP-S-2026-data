#include<bits/stdc++.h>
using namespace std;
int n,a[200006],b[200006];
string s[200006],s2[200006];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>s[i];
		b[n-i+1]=a[i];
		s2[n-i+1]=s[i];
	}
	int i=1,j=1;
	while(i!=n+1){
		if(a[i]>=b[j]){
			a[i]-=b[j++];
			if(s[i]!=s2[j-1]){
				cnt+=b[j-1];
				if(a[i]==0)i++;
			}
		}else{
			b[j]-=a[i++];
			if(s[i-1]!=s2[j])cnt+=a[i-1];
		}
	}
	cout<<cnt/2;
	return 0;
} 
