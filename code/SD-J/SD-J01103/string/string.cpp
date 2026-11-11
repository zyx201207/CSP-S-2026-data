#include<bits/stdc++.h>
using namespace std;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
		l+=a;
	} 
	for(long long i=0,j=l-1;i<=j;i++){
		if(s[i]!=s[j]){
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}

