//цоЁЧЁл  ╦╗бжжпя╖  SN-J00701 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
string s1,s2,s3,s4;bool ans1,ans2,ans3,ans4;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		ans1=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			ans2=1;
			if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')){
				ans3=1;
				if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F')){ans4=1;}
				swap(s2,s4);
				if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F')){ans4=1;}
			}else{ans3=ans4=0;}
		}else{ans2=ans3=ans4=0;}
	}else{
		ans1=ans2=ans3=ans4=0;
	}cout<<ans1<<ans2<<ans3<<ans4<<'\n';
	return 0;
}
