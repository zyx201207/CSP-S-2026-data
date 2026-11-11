#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
		string a1,a2;
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				cout<<ans1<<ans2<<ans3<<ans4;
				return 0;
			}
		}
		ans2=1;
		if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
			ans3=1;
			int b1,b2;
			b1=s1[2]-'0';
			b2=s2[2]-'0';
			if(abs(b1-b2)==1) ans4=1;
		}
		
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
