#include<bits/stdc++.h>
using namespace std;

char c1[5];
char s1[5];
char c2[5];
char s2[5];
char a[5]="0000";

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 
	cin>>c1>>s1>>c2>>s2;
//车厢 
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a[0]='1';
	}else{
		cout<<"0000";
		return 0;
	}
		//同一排 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]='1';
	}else{
		cout<<a[0]<<a[1]<<a[2]<<a[3];
		return 0;
	}
		
		//同一侧（AC
		
	if(s1[2]=='C'&&s2[2]=='A'){
		a[2]='1';
		cout<<a[0]<<a[1]<<a[2]<<a[3];
		return 0;
	}
	
	if(s1[2]=='A'&&s2[2]=='C'){
		a[2]='1';
		cout<<a[0]<<a[1]<<a[2]<<a[3];
		return 0;
	}
		
		//相邻？ 
	if(s1[2]=='F'){
		if(s2[2]=='D'){
			a[2]='1';
			a[3]='1';
			cout<<a[0]<<a[1]<<a[2]<<a[3];
			return 0;
		}
	}	
	
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			a[2]='1';
			a[3]='1';
			cout<<a[0]<<a[1]<<a[2]<<a[3];
			return 0;
		}
	}	
		
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			a[2]='1';
			a[3]='1';
			cout<<a[0]<<a[1]<<a[2]<<a[3];
			return 0;
		}
	}		
	
	if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			a[2]='1';
			a[3]='1';
			cout<<a[0]<<a[1]<<a[2]<<a[3];
			return 0;
		}
	}	
	
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			a[2]='1';
			a[3]='1';
			cout<<a[0]<<a[1]<<a[2]<<a[3];
			return 0;
		}
	}	
	
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
