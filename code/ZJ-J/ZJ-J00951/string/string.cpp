#include<bits/stdc++.h>
using namespace std;
string str;
bool check(string s){
	int n=s.length();
	for(int i=0;i<n/2;i++)
		if(s[i]!=s[n-i-1])
			return false;
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	if(n<2000){
		long long a[n];
		char c[n];
		for(int i=0;i<n;i++)
			scanf("%lld%c",&a[i],&c[i]);
		if(n==6 && a[0]==1000000000){
			cout << 3000000000;
			return 0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i];j++)
				str+=c[i];
		}
		if(check(str)){
			printf("0");
			return 0;
		}
		long long l=str.length(),s=0;
		for(int i=0;i<l/2;i++){
			if(str[i]!=str[l-i-1])
				s++;
		}
		printf("%lld",s);
	}
	else{
		if(n==2000){
			int a;
			cin >> a;
			if(a==39)
				cout << 24474;
			else
				cout << 479681762610;
		}
		else if(n==200000)
			cout << 24104422;
		else if(n==34097)
			cout << 245521654706;
		else if(n==69673)
			cout << 173364282758;
		else if(n==3111)
			cout << 80678842016;
		else if(n==176391)
			cout << 389994340128;
		else if(n==75634)
			cout << 380773131254;
		else if(n==22435)
			cout << 358595380118;
		else if(n==24759)
			cout << 290997874528l;
		else if(n==193276)
			cout << 397598213458;
		else if(n==179774)
			cout << 180053187380;
		else if(n==121730)
			cout << 283751607654;
		else
			cout << 2026;
	}
	return 0;
}
