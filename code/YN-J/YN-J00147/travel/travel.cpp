#include <bits/stdc++.h>
using namespace std;
long long t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	for(int i=0;i<2;i++){//1
		if(s1[i]!=c1[i]){
			t1++;
		}
		else{
			t2++;
		}
	}
	if(t1==0&&t2==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int j=0;j<2;j++){//2
		if((s2[j]!=c2[j])){
			t3++;
		}
		else if((s2[j]==c2[j])&&(s1[j]==c1[j])){
			t4++;
		}
	}
	if(t3==0&&t4==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int j=0;j<2;j++){//3
		if(s2[j]!=c2[j]){
			t5++;
		}
		else if((s2[j]==c2[j])&&(s1[j]==c1[j])){
			t6++;
		}
	}
	for(int j=2;j<3;j++){
		if((s2[j]=='A'&&c2[j]=='B')||(s2[j]=='B'&&c2[j]=='A')||(s2[j]=='C'&&c2[j]=='A')||(s2[j]=='A'&&c2[j]=='C')||(s2[j]=='D'&&c2[j]=='F')||(s2[j]=='F'&&c2[j]=='D')||(s2[j]=='C'&&c2[j]=='B')||(s2[j]=='B'&&c2[j]=='C')&&(s1[j]==c1[j])){
			t7++;
		}
		else{
			t8++;
		}
	}
	if(t5==0&&t6==2&&t7==1&&t8==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int j=0;j<2;j++){//4
		if(s2[j]!=c2[j]){
			t9++;
		}
		else{
			t10++;
		}
	}
	for(int j=2;j<3;j++){
		if((s2[j]=='A'&&c2[j]=='B')||(s2[j]=='B'&&c2[j]=='A')||(s2[j]=='F'&&c2[j]=='D')||(s2[j]=='D'&&c2[j]=='F')||(s2[j]=='B'&&c2[j]=='C')||(s2[j]=='C'&&c2[j]=='B')){
			t11++;
		}
		else{
			t12++;
		}
	}
	if(t9==0&&t10==2&&t11==1&&t12==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
	//02 01A 02 01B ans1111 02 01C 02 01A ans1110 02 01C 02 01D ans1100 02 02B 02 01A ans1000 02 01A 03 01A ans0000
	//全世界最像小学生的做法
}
