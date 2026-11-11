#include<bits/stdc++.h>
using namespace std;
int n,a,sum;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			sum+=a;
		}
	}
	int ans=0;
	bool b=0;
	for(int h=1,l=sum;h<=l;h++,l--){
		if(s[h]!=s[l]){
			ans++;
		}
		else b=1;
	}
	if(!b)cout<<ceil(ans*1.0/2);
	else cout<<0;
	return 0;
}
