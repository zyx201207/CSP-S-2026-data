#include<bits/stdc++.h>
using namespace std;

bool ans[9]={0};

bool f(char a,char b){
	bool f1=0,f2=0;
	string t1="ABC",t2="DF";
	//cout<<a<<" "<<b<<'\n';
	for(int i=0;i<=1;i++){
		//cout<<t2[i]<<" "<<a<<" "<<b<<'\n'; 
		if(t2[i]==a) f1=true;
		if(t2[i]==b) f2=true;
	}
	//cout<<f1<<" "<<f2<<'\n';
	return f1==f2?1:0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1.size()<2) c1="0"+c1;
	if(c2.size()<2) c2="0"+c2;
	if(s1.size()<3) s1="0"+s1;
	if(s2.size()<3) s2="0"+s2;
	
	c1=" "+c1;
	s1=" "+s1;
	c2=" "+c2;
	s2=" "+s2;
	string t1,t2;
	t1=t1+" "+s1[1]+s1[2];
	t2=t2+" "+s2[1]+s2[2];
	
	if(c1==c2) ans[1]=1;
	else{
		for(int i=1;i<=4;++i){
			cout<<ans[i];
		}
		return 0;
	}
	if(c1==c2 && t1==t2) ans[2]=1;
	else{
		for(int i=1;i<=4;++i){
			cout<<ans[i];
		}
		return 0;
	}
	if(f(s1[3],s2[3]) ) ans[3]=1;
	else{
		for(int i=1;i<=4;++i){
			cout<<ans[i];
		}
		return 0;
	}
	if(s1[3]=='D' && s2[3]=='F'||
	   s1[3]=='F' && s2[3]=='D'){
		ans[4]=1;
		for(int i=1;i<=4;++i){
			cout<<ans[i];
		}
		return 0;
	}
	else if(s1[3]=='B'||s2[3]=='B'){
		ans[4]=1;
		for(int i=1;i<=4;++i){
			cout<<ans[i];
		}
		return 0;
	}
	for(int i=1;i<=4;++i){
		cout<<ans[i];
	}
	
	return 0;
}
