#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		string ss="";
		for(long long i=1;i<=10000;i++){
			ss+=c;
		}
		while(a>=10000){
			s+=ss;
			a-=10000;
		}
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
//	cout<<s;
	long long Size=s.size();
	for(long long i=0;i<Size/2;i++){
		if(s[i]!=s[Size-1-i]){
			s[i]=s[Size-1-i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
