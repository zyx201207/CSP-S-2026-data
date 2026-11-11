#include<bits/stdc++.h>
using namespace std;
vector<char>str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		int n;
		char m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			str.push_back(m);
		}
	}
	int len=str.size();
	int cen;
	if(len%2==1){
		cen=len/2+1;
	}else{
		cen=len/2;
	}
	int c=0;
	for(int i=0;i<cen;i++){
		if(str[i]==str[len-i]){
			continue;
		}else{
			c++;
		}
	}
	cout<<c;
	return 0;
}
