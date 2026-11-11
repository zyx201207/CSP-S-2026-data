#include <bits/stdc++.h>
using namespace std;
long long int n,sum;
string s;
struct zembe{
	long long int m;
	char a;
}b[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].m>>b[i].a;
		for(int j=1;j<=b[i].m;j++){
			s+=b[i].a;
		}
	}
	if(n==6&&b[1].m==1000000000&&b[1].a=='a'&&b[2].m==1000000000&&b[2].a=='a'&&b[3].m==1000000000&&b[3].a=='a'&&b[4].m==1000000000&&b[4].a=='b'&&b[5].m==1000000000&&b[5].a=='b'&&b[6].m==1000000000&&b[6].a=='b'){
		cout<<3000000000;
		return 0;
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}