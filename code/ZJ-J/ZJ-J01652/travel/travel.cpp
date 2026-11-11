#include<bits/stdc++.h>
using namespace std;
int c1,c2,cnt1,cnt2;
string s1,s2;
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A')	cnt1=1;
	if(s1[2]=='B')	cnt1=2;
	if(s1[2]=='C')	cnt1=3;
	if(s1[2]=='D')	cnt1=4;
	if(s1[2]=='F')	cnt1=5;
	
	if(s2[2]=='A')	cnt2=1;
	if(s2[2]=='B')	cnt2=2;
	if(s2[2]=='C')	cnt2=3;
	if(s2[2]=='D')	cnt2=4;
	if(s2[2]=='F')	cnt2=5;
	if(c1!=c2){
		ans1=0;
		ans2=0;
		ans3=0;
		ans4=0;
	}else{
		ans1=1;
		if(s1[0]!=s2[0] || s1[1]!=s2[1]){
			ans2=0;
			ans3=0;
			ans4=0;
		}	
		else{
			ans2=1;
			if( ((0<cnt1 && cnt1<4)&&(3<cnt2 && cnt2<6)) || ((0<cnt2 && cnt2<4)&&(3<cnt1 && cnt1<6)) ){
				ans3=0;
				ans4=0;
			}
			else{
				ans3=1;
				if(abs(cnt1-cnt2)!=1){
					ans4=0;
				}
				else	ans4=1;
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;          
	return 0;
}
