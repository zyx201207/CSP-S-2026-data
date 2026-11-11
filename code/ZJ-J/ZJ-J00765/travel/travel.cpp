#include<bits/stdc++.h>
using namespace std;

int read(){
	int f=1,cnt=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		cnt=cnt*10+ch-'0';
		ch=getchar();
	}
	return f*cnt;
}
string c1,s1,c2,s2,ans="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans="1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans+="1";
			if( (s1[2]<='C' && s1[2]>='A' && s2[2]<='C' && s2[2]>='A')){
				ans+="1";
				if(abs(s1[2]-s2[2])==1) ans+="1";
				else ans+="0";
			}else if((s1[2]<='F' && s1[2]>='D' && s2[2]<='F' && s2[2]>='D')){
				ans+="11";
			}
			else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}
	else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
/*
12 11D 12 11F
*/
