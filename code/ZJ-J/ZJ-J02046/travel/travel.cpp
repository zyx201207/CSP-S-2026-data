#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	string m,n;
	for(int i=0;i<2;i++){
		m+=s1[i];
		n+=s3[i];
	}
	bool v;
	if(s==s2){
		cout<<1;
		if(m==n){
			cout<<1;
			if(s1[2]<='C'&&s3[2]<='C'||s1[2]>='D'&&s3[2]>='D'){
				cout<<1;
				if(abs(int(s1[2]-s3[2]))==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}                                    