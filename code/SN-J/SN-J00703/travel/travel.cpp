//yangzirui xianjiaotongdaxuefushuzhongxue SN-J00703
#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a1,a2,ans1,ans2;
int changess(string s){
	int ans=0;
	int a=s.length();
	for(int i=0;i<a;i++){
		int num1=int(s[i])-int('0');
		if(num1>=0 && num1<=9) ans=ans*10+num1;
		else break;
	}
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool num=true;
	cin>>c1>>c2>>c3>>c4;
	a1=changess(c1);a2=changess(c2);ans1=changess(c3);ans2=changess(c4);
	int a,b;
	a=int(c2[2])-int('A')+1;
	b=int(c4[2])-int('A')+1;
	if(a1==ans1 && num) cout<<1;
	else{
		cout<<0000;
		num=0;
	}
	if(a2==ans2 && num) cout<<1;
	else{
		cout<<000;
		num=0;
	}
	if(((a>=1 && a<=3)&&(b>=1 && b<=3) || (a>=4 && a<=5)&&(b>=4 && b<=5)) && num) cout<<1;
	else{
		cout<<00;
		num=0;
	}
	if((a-b==1 || a-b==-1) && num) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
