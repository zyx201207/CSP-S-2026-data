#include<bits/stdc++.h>
using namespace std;
int a[6][18];
int main(){
	
	bool k(a,b){
		switch(s1[]=="A"||b=="B"||c=="C"||d=="D"){
			if(s1[2]=='A')
				if(s1[2]=='B'){
					be= true;
				}else{
					be= false;
				}
			if(s1[2]=='B')
				if(s2[2]=='A'){
					be= true;
				}else if(s2[2]=='C')){
					be=false;
				}
			if(s1[2]=='C')
				if(s3[2]=='D'){
					be=true;
				}else{
					be=false;
				}
			if(s1[2]=='D')
				if(s4[2]=='C'){
					be=true;
				}else{
					be=false;
				}
			if(s1[2]=='E')
			    if(s5[2]=='F'){
			    	be=true;
				}else{
					be=false;
				}
			if(s1[2]=='F')
			    if(s6[2]=='E'){
			    	be=true;
				}else{
					be=false;
				}
		}
		
	}         
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1;
	string c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c=false,p=false,m=false,be=false;
	for(int i=0;i<s1.size();i++){
		if(c1!=c2){
			cout<<c<<p<<m<<be;
			return 0;
		}else{
			c=true;
			if(s1[0]==s2[0]){
				p=true;
				if(s1[1]==s2[1]){
					m=true;
				}
			}
		}
	}
	cout<<c1<<'\n'<<c2<<'\n'<<s1<<'\n'<<s2<<'\n';
	return 0;
}
