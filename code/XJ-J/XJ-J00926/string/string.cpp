#include <bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a;
	char b;
	for(long long i=1;i<=n;i++){
		cin >> a >> b;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
	long long len=s.size()-1;
	long long sum=0,ant=0;
	while(sum<len){
		if(s[sum]!=s[len]) ant++;
		sum++;
		len--;
	}
	cout << ant;
	return 0;
}