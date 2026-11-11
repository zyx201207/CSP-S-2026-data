#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","r",stdout);
	char c1[5],s1[5],c2[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	int c1sum=1,s1sum=0,c2sum=0,s2sum=0,a=1,b=1,c=0;
	for(int i=0;i<strlen(c1);i++){
		if(c1[i]!=c2[i]){
			c1sum=0;
			c2sum=0;
			s1sum=0;
			s2sum=0;
			cout<<c1sum<<c2sum<<s1sum<<s2sum;
			a=0;
			return 0;
		}
	}
	if(a==1){
		for(int j=0;j<strlen(s1)-1;j++){
			int b=1;
			c=j+1;
			if(s1[j]!=s2[j]){
				b=0;
				c2sum=0;
				s1sum=0;
				s2sum=0; 
				b=0;
				cout<<c1sum<<c2sum<<s1sum<<s2sum;
				return 0;
			}
		}
		if(b==1){
			c2sum=1;
			if((s1[c]=='C'&&s2[c]=='D')||(s1[c]=='D'&&s2[c]=='C')){
				s1sum=0;
				s2sum=0;
			}else if((s1[c]=='F'&&s2[c]=='D')||(s1[c]=='D'&&s2[c]=='F')){
				s1sum=1;
				s2sum=1;
			}else if(s1[c]-1==s2[c]||s1[c]+1==s2[c]){
				s1sum=1;
				s2sum=1;
			}else{
				s1sum=1;
				s2sum=0;
			}	
		}
	}
	cout<<c1sum<<c2sum<<s1sum<<s2sum;	
	return 0;
}
