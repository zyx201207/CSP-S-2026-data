#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char c;
	string s,d="00";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			d+=c;
		}
	}s=d.substr(2);
	long long cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
