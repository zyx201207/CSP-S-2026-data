#include<bits/stdc++.h>
using namespace std;
string sh1,sh2;
int fx1,fx2,ch1,ch2;
char zw1,zw2;
bool ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>fx1>>sh1>>fx2>>sh2;
	ch1=(sh1[0]-'0')*10+(sh1[1]-'0');
	ch2=(sh2[0]-'0')*10+(sh2[1]-'0');
	zw1=sh1[2];
	zw2=sh2[2];
	ans1=(fx1==fx2);
	if(ans1){
		ans2=(ch1==ch2);
		if(ans2){
			if((zw1<='C'&&zw2<='C')||(zw1>='D'&&zw2>='D')){
				ans3=1;
			}else{
				ans3=0;
			}
			if(zw1>='D'){
				zw1++;
			}
			if(zw2>='D'){
				zw2++;
			}
			if(abs(int((zw1-zw2)))==1){
				ans4=1;
			}else{
				ans4=0;
			}
		}		
	}	
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}

