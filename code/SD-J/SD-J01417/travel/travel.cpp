#include <bits/stdc++.h>
using namespace std;
int _11,_12,_21,_22;
char _1,_2;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	

	cin>>_11;
	getchar();
	_12=(getchar()-'0')*10+getchar()-'0';
	_1=getchar();
	getchar();
	
	cin>>_21;
	getchar();
	_22=(getchar()-'0')*10+getchar()-'0';
	_2=getchar();
	getchar();
	
	if(_2<_1)swap(_1,_2);
	
	//--
//	cout<<_11<<' '<<_12<<' '<<_1<<' '<<_21<<' '<<_22<<' '<<_2<<' ';
	
	//--
	
	if(_11==_21)
	{
		cout<<"1";
		if(_12==_22){
			cout<<"1";
			if(_1+_2==138)
			cout<<"11";
			else if((_1=='A'&&_2=='B')||(_1=='B'&&_2=='C'))
			cout<<"11";
			else if(_1=='A'&&_2=='C') 
			cout<<"10";
			else cout<<"00";
		}
		else cout<<"000";
	}else cout<<"0000";
	
	fclose(stdout);
	fclose(stdin); 
	
	return 0;
} 
