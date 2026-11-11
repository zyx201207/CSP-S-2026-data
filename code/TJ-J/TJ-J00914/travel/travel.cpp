#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]='1';
			if((s1[2]<'c'&&s2[2]<'c')||(s1[2]>='c'&&s2[2]<'c')){
				a[2]='1';
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					a[3]='1';
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
