#include<bits/stdc++.h>
using namespace std;
struct zw_chm{
	int lie,hang;
}zs1,zs2;
string c1,s1,c2,s2;
int ic1,ic2;
inline int c2i_chm(string c){
	int ret=0;
	for(int i=0;i<c.size();i++){
		if(c[i]=='0')
			continue;
		ret=ret*10+c[i]-'0';
	}
	return ret;
}
inline s2z_chm(string s,zw_chm &ans){
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')
			continue;
		if(s[i]>='0'&&s[i]<='9'){
			ans.lie=ans.lie*10+s[i]-'0';
		}else if((s[i]>='A'&&s[i]<='D')||s[i]=='F'){
			switch(s[i]){
				case'A':ans.hang=1;continue;
				case'B':ans.hang=2;continue;
				case'C':ans.hang=3;continue;
				case'D':ans.hang=5;continue;
				case'F':ans.hang=6;continue;
			} 
		}
	}
}
inline bool chk(int x,int y){
	if(x<=3&&y<=3&&x>=1&&y>=1)
		return 1;
	if(x<=6&&y<=6&&x>=5&&y>=5)
		return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ic1=c2i_chm(c1);
	ic2=c2i_chm(c2);
	s2z_chm(s1,zs1);
	s2z_chm(s2,zs2);
	if(ic1!=ic2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		if(zs1.lie!=zs2.lie){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			if(!chk(zs1.hang,zs2.hang)){
				cout<<"00";
				return 0;
			}else{
				cout<<1;
				if(zs1.hang-zs2.hang==1||zs2.hang-zs1.hang==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
