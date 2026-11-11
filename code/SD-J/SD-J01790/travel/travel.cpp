#include<iostream>
#include<cstring>
#define int long long
using namespace std;
string s1,s2;
string c1,c2;
bool flag[8];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			flag[2]=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				flag[3]=1;
				if((s1[2]+1==s2[2]||s2[2]+1==s1[2])){
//					if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D'));
					flag[4]=1;
				}
			}
		}
	} 
	for(int i=1;i<=4;i++){
		cout<<flag[i];
	}
}
