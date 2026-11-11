#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen('travel.in','r',stdin);
	freopen('travel.out','w',stdout);
	int a=0,b=0,c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){cout<<"1";
		b=1;}
	else cout<<"0";
	
	
	if(b==1 && int(s1[0])==int(s2[0]) && int(s1[1])==int(s2[1])){
	cout<<"1";
	
	a=1;
	}
	else cout<<"0";
//	cout<<"  "<<s1[0]<<"  "<<s2[0]<<"    "<<s1[1]<<"  "<<
	
	
	
	
	
	
	if(b==1 && a==1 && (68<=int(s1[2])<=70 || 65<=int(s1[2])<=67) && (68<=int(s2[2])<=70 
	   || 65<=int(s2[2])<=67)){
		   if((int(s1[2])!=67 && int(s2[2])!=68) || (int(s1[2])!=68 &&
	             int(s2[2])!=67)) cout<<"1";
				else cout<<"0";
		   }
	else cout<<"0";
	
	
	if(b==1 && a==1 && 70<=int(s1[2])<=65 && 70<=int(s2[2])<=65 && (int(s1[2])-int(s2[2])==1 ||
	    int(s2[2])-int(s1[2])==1) && (int(s1[2])!=67 || int(s1[2])!=68 &&
	    int(s2[2])!=67 || int(s2[2])!=67)) cout<<"1";
	else{
			if(b==1 && int(s1[2])==70 || int(s1[2])==68 && int(s2[2])==70 
			   || int(s2[2])==67) cout<<"1";
			else cout<<"0";
		} 
//	 A 65 B 66 C 67 D 68 F 70
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
