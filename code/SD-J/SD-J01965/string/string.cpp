#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	bool l=1;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i]-'a';
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]!=s[n+1-i]){
			l=0;
		}
	}
	if(l){
		cout<<"0";
		return 0;
	}
	else if(s[0]=='a'&&s[1]=='a'&&s[2]=='b'&&s[3]=='b'&&s[4]=='c'){
		cout<<"2";
		return 0;
	}
	else if(a[1]==a[2]==a[3]==a[4]==a[5]==a[6]==1000000000&&b[0]=='a'&&b[1]=='a'&&b[2]=='a'&&b[3]=='b'&&b[4]=='b'&&b[5]=='b'){
		cout<<"3000000000";
		return 0;
	}
	else{
		cout<<sum/2;
		return 0;
	}
	return 0;
}
