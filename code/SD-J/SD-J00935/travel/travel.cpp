#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int w1,w2;
char e1,e2;
bool xiang,pai,ce,lin;
int main(){
	freopen("travel.in","r",stdin);
	freopen("teavel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	w1=(s1[0]-'0')*10+s1[1]-'0';
	w2=(s2[0]-'0')*10+s2[1]-'0';
	e1=s1[2];
	e2=s2[2];
	//cout<<w1<<" "<<w2<<" "<<e1<<" "<<e2<<endl;
	if(c1==c2){
		xiang=1;
			 if(w1==w2){
	 	pai=1;
		 if(e1>='A'&&e1<='C'&&e2>='A'&&e2<='C'||e1>='D'&&e1<='F'&&e2>='D'&&e2<='F')
	{
		ce=1;
		if(e1+1==e2||e1-1==e2)
		lin=1;
	}
	 }
	}

	cout<<xiang<<pai<<ce<<lin;
	return 0;
	
}
