#include <bits/stdc++.h>
using namespace std;
string s[8];
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bool b=true;
	for(int i=1;i<=4;i++)
		cin>>s[i];
	if(s[1]==s[3]){
		 a[1]=1;
		for(int i=0;i<=1;i++){
			if(s[2][i]!=s[4][i])
				b=false;
		}if(b){
			a[2]=1;
			if((s[2][2]-'A'<=2 && s[4][2]-'A'<=2)||(s[2][2]-'A'>=3 && s[4][2]-'A'>=3)){
				a[3]=1;
				if(abs(s[4][2]-s[2][2])==1)
					a[4]=1;
			}
		}
	}for(int i=1;i<=4;i++)
		cout<<a[i];	
	return 0;
}
