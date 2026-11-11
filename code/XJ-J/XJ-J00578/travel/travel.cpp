#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,SUM;
int cnt1,cnt2,cnt3,cnt4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cnt1++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cnt2++;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
					cnt3++;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
					cnt4++;
				}
			}
		}	
	}
	if(cnt1==1) SUM+='1';
	else SUM+='0';
	if(cnt2==1) SUM+='1';
	else SUM+='0';
	if(cnt3==1) SUM+='1';
	else SUM+='0';
	if(cnt4==1) SUM+='1';
	else SUM+='0';
	cout<<SUM;
	return 0;
}