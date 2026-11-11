#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,a,s3,b;
	cin>>s1>>a>>s3>>b;
	if(s1==s3){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			char q=a[2],e=b[2];
			if(q=='A'||q=='B'||q=='C'){
				if(e=='A'||e=='B'||e=='C'){
					cout<<1;
					if(q=='A'&&e=='B') cout<<1;
					else if(q=='B'&&(e=='A'||e=='C')) cout<<1;
					else if(q=='C'&&e=='B') cout<<1;
					else cout<<"0";
				}else cout<<"00";
			}else if(q=='D'){
				if(e=='F'){
					cout<<11;
				}else cout<<"00";
			}else if(q=='F'){
				if(e=='D'){
					cout<<11;
				}else cout<<"00";
			}
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
/*
01 02B 02 01A
*/
