#include<bits/stdc++.h>
using namespace std;
int a[100];
char ch[100];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>ch[i];
	}
	int len=strlen(ch);
	for(int i=0;i<len;i++){
		s[i]=ch[i];
	}
	string re=s;
	reverse(s.begin(),s.end());
	if(s==re){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
