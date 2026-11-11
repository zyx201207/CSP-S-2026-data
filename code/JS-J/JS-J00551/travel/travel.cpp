#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	int cc=(c[0]-'0')*10+c[1]-'0',dd=(d[0]-'0')*10+d[1]-'0';
	c=c[2];
	d=d[2];
	if(a==b){
		cout<<"1";
		if(cc==dd){
			cout<<"1";
			if((c=="A"&&d=="B")||(c=="A"&&d=="C")||(c=="B"&&d=="C")||(c=="B"&&d=="A")||(c=="C"&&d=="A")||(c=="C"&&d=="B")||(c=="D"&&d=="F")||(c=="F"&&d=="D")){
				cout<<"1";
				 if((c=="A"&&d=="B")||(c=="B"&&d=="A")||(c=="B"&&d=="C")||(c=="C"&&d=="B")||(c=="D"&&d=="F")||(c=="F"&&d=="D")){
					 cout<<"1";
				 }else{
					 cout<<"0";
				 }
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
