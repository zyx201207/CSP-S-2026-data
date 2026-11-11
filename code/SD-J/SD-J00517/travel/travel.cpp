#include<bits/stdc++.h>
#include<string>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1] && s1[0] == s2[0]){
			cout<<1;
			if((s1[2] <= 'C' && s2[2] <= 'C')||(s1[2]>= 'D' && s2[2] >= 'D')){
				cout<<1;
				if((s1[2] <= 'B'&&s2[2]<= 'B') || (s1[2] != 'A' && s2[2] != 'A' && s1[2] <= 'C' && s2[2] <= 'C') || (s1[2]>= 'D' && s2[2] >= 'D' && s1[2] <= 'E' && s2[2]<= 'E')){
					cout<<1<<endl;
				}else{
					cout<<0<<endl;
				}
			}else{
				cout<<0<<0<<endl;
			}
		}else{
			cout<<0<<0<<0<<endl;	
		}
	}
	else{
		cout<<0<<0<<0<<0<<endl;
	}
    return 0;
}
