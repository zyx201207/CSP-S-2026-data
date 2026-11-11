#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int cnt=0;
		int ai;
		char ci;
		cin>>ai>>ci;
		string s;
		if(s[i]!=ci){
			cnt++;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
