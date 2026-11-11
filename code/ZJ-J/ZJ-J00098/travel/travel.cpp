#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
int main(){
	ios::sync_with_stdio(NULL);
	cout.tie(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
