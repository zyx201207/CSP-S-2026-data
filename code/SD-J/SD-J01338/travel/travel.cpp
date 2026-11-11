#include<bits/stdc++.h>
using namespace std;
void s(){
	string c,s,t,r,u,v,w,x,sn;
	cin>>c>>s>>t>>r;
	
	for(int i=1;i<=s.size();i++){
		if(s[i]!='A'&&s[i]!='B'&&s[i]!='C'&&s[i]!='D'&&s[i]!='E') u+=s[i];
		else w+=s[i];
	}
	for(int j=1;j<=r.size();j++){
		if(r[j]!='A'&&r[j]!='B'&&r[j]!='C'&&r[j]!='D'&&r[j]!='E') v+=r[j];
		else x+=r[j];
	}
	 
	if(c!=t) sn+="0000"; 
	if(c==t){
		sn+="1";
		if(u!=v) sn+="000";
		if(u==v){
			sn+="1";
			if(w=="A"&&x=="B") sn+="11";
			if(w=="A"&&x=="C") sn+="10";
			if(w=="A"&&x=="D") sn+="00";
			if(w=="A"&&x=="F") sn+="00";
			if(w=="B"&&x=="C") sn+="11";
			if(w=="B"&&x=="D") sn+="00";
			if(w=="B"&&x=="F") sn+="00";
			if(w=="C"&&x=="D") sn+="00";
			if(w=="C"&&x=="F") sn+="00";
			if(w=="D"&&x=="F") sn+="11";
			if(w=="B"&&x=="A") sn+="11";
			if(w=="C"&&x=="A") sn+="10";
			if(w=="D"&&x=="A") sn+="00";
			if(w=="F"&&x=="A") sn+="00";
			if(w=="C"&&x=="B") sn+="11";
			if(w=="D"&&x=="B") sn+="00";
			if(w=="D"&&x=="C") sn+="00";
			if(w=="F"&&x=="B") sn+="00";
			if(w=="F"&&x=="C") sn+="00";
			if(w=="F"&&x=="D") sn+="11";
		}
	}
	
	cout<<sn;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	s(); 
	return 0;
} 
