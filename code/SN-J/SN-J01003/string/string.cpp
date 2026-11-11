#include <bits/stdc++.h>
using namespace std;

string hw;
string hhw;
long long n,s;
string ans;
long long c=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>ans;
		for(int i=1;i<=s;i++){
			hw+=ans;
		}
	}
	for(int i=hw.size()-1;i>=0;i--){
		hhw+=hw[i];
	}
	for(int i=0;i<hw.size();i++){
		if(hw[i]!=hhw[i]){
			c++;
		}
	}
	cout << c/2;
	return 0;
}
