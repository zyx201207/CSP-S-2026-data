#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long cishu;
	int a=0;
	for(int i=0;i<n;i++){
		cin>>cishu;
		for(int j=0;j<cishu;j++){
			cin>>s[a];
		    a+=1;
		}
	}
	long long b=s.size()/2;
	long long xiugai=0;
	for(int i=0;i<b;i++){
		if(s[i]!=s[s.size()]-i){
			xiugai+=1;
		}
	}
	cout<<xiugai<<endl;
	return 0;
}
