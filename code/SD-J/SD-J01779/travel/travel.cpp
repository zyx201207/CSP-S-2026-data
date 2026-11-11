#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb; 
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(aa[0]==bb[0]&&aa[1]==bb[1]&&a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(aa[0]==bb[0]&&aa[1]==bb[1]&&a==b&&(aa[2]=='A'||aa[2]=='B'||aa[2]=='C')&&(bb[2]=='A'||bb[2]=='B'||bb[2]=='C')||(aa[2]=='D'&&aa[2]=='E')&&(bb[2]=='D'&&bb[2]=='E')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(abs(aa[2]-bb[2])==1&&aa[0]==bb[0]&&aa[1]==bb[1]&&a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
