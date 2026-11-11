#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[1005],cnt=0;
	string c[1005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int b=s.size();
	if(b%2!=0){
		b-=1;
	}
	for(int i=0;i<b/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}

	cout<<cnt;
	return 0;	
}
