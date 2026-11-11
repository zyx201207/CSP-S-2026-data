#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
bool f=true,f1=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char str;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(f){
			str=c;
			f=false;
		}
		while(a--){
			s+=c;
		}
		if(str!=c)f1=false;
	}
	if(f1){
		cout<<0<<endl;
		return 0;
	}
	long long st=s.size();
	long long sum=0;
	for(long long i=0;i<=st/2-1;i++){
		if(s[i]!=s[st-i-1]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
