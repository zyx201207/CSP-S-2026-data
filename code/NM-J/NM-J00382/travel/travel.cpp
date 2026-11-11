#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string r1;
	string s1;
	string r2;
	string s2;
	cin>>r1>>s1>>r2>>s2;
	if(r1==r2){
	cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	string n;
	string m;
	vector<int>a;
	vector<int>b;
	int c=0;
	for(int i=0;i<s1.length ()-1;i++){
		if(s1[i]=='0'||s1[i]<='1'||s1[i]=='2'||s1[i]=='3'||s1[i]=='4'||s1[i]=='5'||s1[i]=='6'||s1[i]=='7'||s1[i]=='8'||s1[i]=='9'){
			n[i]=s1[i];
		}
		if(s2[i]=='0'||s2[i]=='1'||s2[i]=='2'||s2[i]=='3'||s2[i]=='4'||s2[i]=='5'||s2[i]=='6'||s2[i]=='7'||s2[i]=='8'||s2[i]=='9'){
			m[i]=s2[i];
		}
	if(n[i]==m[i]){
		c++;
	}
	}
 if(c==2){
 	cout<<1;
 }else{
 	cout<<0;
 	cout<<0;
 	cout<<0;
 	return 0;
 }
 c=0;
 int d=0;
 int f=0;
 
	for(int i=0;i<s1.length ()-1;i++){
		if(s1[i]=='0'||s1[i]<='1'||s1[i]=='2'||s1[i]=='3'||s1[i]=='4'||s1[i]=='5'||s1[i]=='6'||s1[i]=='7'||s1[i]=='8'||s1[i]=='9'){
			s1.erase(s1.begin()+i);
		}
		if(s2[i]=='0'||s2[i]=='1'||s2[i]=='2'||s2[i]=='3'||s2[i]=='4'||s2[i]=='5'||s2[i]=='6'||s2[i]=='7'||s2[i]=='8'||s2[i]=='9'){
			s2.erase(s2.begin()+i);
		}
			 d=s1[1]-'0';
			 f=s2[1]-'0';
	}
	if(d+1==f||d+2==f){
		if(d==18&&f==20){
			cout<<0;
			cout<<0;
			return 0;
		}
		if(d==19&&f==22){
			cout<<0;
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
		}
	}
else{
	if	(f+1==d||f+2==d){
	
		if(f==18&&d==20){
			cout<<0;
			cout<<0;
			return 0;
		}
		if(f==19&&d==22){
			cout<<0;
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
		
		}
}
	else{
		
			cout<<0;
			cout<<0;
			return 0;
	
	}
	}
	if(d+1==f){
		if(d==20&&f==21){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
//	string n1;
//	string m1;
// 	for(int i=0;i<s1.length ()-1;i++){
//	if(s1[i]>='A'&&s1[i]<='Z'){
//			n1[i]=s1[i];
//			
//		}	
//	if(s2[i]>='A'&&s2[i]<='Z'){
//		m1[i]=s2[i];
//	
//	}	
////	if((m1[i]=='A'||m1[i]=='B'||m1[i]=='C')&&(n1[i]=='A'||n1[i]=='B'||n1[i]=='C')){
////		c++;
////	}
//	}
//	if(c>=1){
//		cout<<1; 
//	}else{
//		cout<<0;
//	}
	return 0;
}
