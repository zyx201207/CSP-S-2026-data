#include<bits/stdc++.h>
using namespace std;
int a,b;
int m,n;
char x,y;

string ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>x;
	cin>>b>>n>>y;
	if(a!=b){
		ans+="0";
		cout<<"0000"<<endl;
		return 0;
	}else{
		ans+="1";
	}
	
	if(m!=n){
		ans+="0";
		cout<<"1000"<<endl;
		return 0;
	}else{
		ans+="1";
	}
	
	if((int(x)>=65&&int(x)<=67&&int(y)>=65&&int(y)<=67)||(int(x)>=68&&int(x)<=70&&int(y)>=68&&int(y)<=70)){
		ans+="1";
	}else{
		ans+="0";
	}
	
	if(ans[2]=='0'){
		ans+="0";
		cout<<ans<<endl;
		return 0;
	}else if(int(x)>=65&&int(x)<=67){
		if(int(x)+1==int(y)||int(x)-1==int(y)){
			ans+="1";
			cout<<ans<<endl;
			return 0;
		}
	}else if(int(x)>=68&&int(x)<=70){
		if(int(x)+2==int(y)||int(x)-2==int(y)){
			ans+="1";
			cout<<ans<<endl;
			return 0;
		}
	}
	ans+="0";
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

