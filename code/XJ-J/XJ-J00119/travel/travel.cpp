#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool t1,t2,t3,t4;
char w1 ,w2;
int q1,q2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	t1=(c1==c2);
	
	q1=(s1[0]-'0')*10+(s1[1]-'0');
	q2=(s2[0]-'0')*10+(s2[1]-'0');
	t2=(q1==q2);
	t2=(t1&&t2);
	w1=s1[2];
	w2=s2[2];
	t3=(w1>='A'&&w1<='C'&&w2>='A'&&w2<='C'||(w1=='D'||w1=='F')&&(w2=='D'||w2=='F'));
	t3=(t2&&t3);
	for(char a='A';a<='C';a++ ){
		if(w1==a&&(w2==a+1||w2==a-1)) {
			t4=1;
		}
		
	} 
	if(w1=='D'&&w2=='F'||w2=='D'&&w1=='F')
		t4=1;
	t4=(t4&&t3);
	cout<<t1<<t2<<t3<<t4;
	return 0;
} 
