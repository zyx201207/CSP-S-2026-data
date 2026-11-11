#include <bits/stdc++.h> 
using namespace std;
 int main()
 {
 	freopen("travel.in()","r",stdin);
 	freopen("travel.out()","w",stdout);
 	string c1,s1,c2,s2,n;
 	int a[10];
 	if(c1==c2){
 		a[0]=0;
	}
	else{
		a[0]=1;
	}
	for(int i=0; i<=s1.size()-1; i++){
		if(s1[i]==s2[i]){
			a[1]=0;
		}
		else{
			a[1]=1;
		}
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		a[2]=0;
	}
	else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
		a[2]=0;
	}
	else{
		a[2]=1;
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'){
		a[3]=0;
	}
	else if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D'){
		a[3]=0;
	}
	else{
		a[3]=1;
	}
	for(int j=0; j<=4; j++){
		n[j]=a[j];
	}
	cout << n;
 	return 0;
 }
