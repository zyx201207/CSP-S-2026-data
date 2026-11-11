//maqinxin kunluzhongxue SN-J00670
#include<math>
#include<bits/stdc++.h>

using namespace std;
int main(){
	string s,t;
	int a,b,len;
	char c[500];
	cin>>a;
	for(int i=1;i<=a*2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
	for(int t=1;t<=c[i];i++)
		s[t]=c[i+1];
	}

	for(int i=size.s;i>0;i--){
		t[i]=s[i];
	}
	for(int i=1;i<=size.s;i++){
		if(s[i]!=t[i]){
			b++;
		}
	}
	cout<<b;
	return 0;}
