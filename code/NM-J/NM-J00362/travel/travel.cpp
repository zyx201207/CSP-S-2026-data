#include<bits/stdc++.h>
using namespace std;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
	}else cout<<"0";
	
	string se=b,sea=d;
se=	se.substr(0,2);
//	cout<<se<<endl;
sea=	sea.substr(0,2);
	if(se==sea){
		cout<<"1";
		
	}else cout<<"0";
	if(se==sea&&b[2]>='A'&&b[2]<='C')
	cout<<"1";
	else cout<<"0";
	if(b[2]+1==d[2]||b[2]-1==d[2])
	cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}

