#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		while(a[i]--){
			s=s+c[i];
		}
	}
	long long sum=0;
	for(int i=1;i<=l/2;i++){
		if(s[i-1]!=s[l-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
