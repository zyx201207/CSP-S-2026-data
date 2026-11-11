#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
string c1,c2,s1,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+="1";
	else{
		cout<<"0000";
		return 0;
	}if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+="1";
	}else{
		cout<<"1000";
		return 0;
	}int a1=s1[2]-'A',a2=s2[2]-'A';
	if((a1>=0&&a1<=2&&a2>=0&&a2<=2)||(a1>=3&&a1<=5&&a2>=3&&a2<=5)){
		ans+="1";
	}else{
		cout<<"1100";
		return 0;
	}if(a1<a2)swap(a1,a2);
	if(a1-a2==1||(a1==5&&a2==3)){
		cout<<ans<<"1";
	}else{
		cout<<ans<<"0";
	}
	
	return 0;
} 
