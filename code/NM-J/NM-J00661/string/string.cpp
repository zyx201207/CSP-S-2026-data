#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	string s;
	unsigned long long n=0,a=0,cnt=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]) cnt++;
	}
	cout<<cnt;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
