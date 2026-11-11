#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
int a,b;
	int a1,a2,b1,b2;
	string c,d;
	char s1,s2;
	cin>>a>>c>>b>>d;
	a1=(c[0]-'0')*10+(c[1]-'0');
	b1=(d[0]-'0')*10+(d[1]-'0');
	s1=c[2];
	s2=d[2];
	a2=s1-'A'+1;
	b2=s2-'A'+1;
		if(a==b){
		cout<<"1";
		 if(a1==b1){
		 cout<<"1";
		 
		 if(a2+b2==9)cout<<"11";
		 else if(a2+b2==9)cout<<"11";
		 else if(a2+b2==3)cout<<"11";
		 else if(a2+b2==5)cout<<"11";
		 else if(a2+b2==4) cout<<"10";
		 else cout<<"00";
		 
		 }else cout<<"000";
		}
	else cout<<"0000";
	
		fclose(stdin);
	fclose(stdout);
	return 0;
}