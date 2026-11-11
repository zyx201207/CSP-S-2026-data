#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	bool s1=0,s2=0,s3=1,s4=0;
	int p1=0,p2=0;
	char c1,c2;
	c1=rb[rb.size()-1];
	c2=xb[xb.size()-1];
	if(ra==xa){
		s1=1;
		for(int i=0;i<2;i++){
			p1+=(rb[i]-'0')*(i+1)*10;
			p2+=(xb[i]-'0')*(i+1)*10;
		}
		if(p1==p2){
			s2=1;
			if((c1=='C'&&c2=='D')||(c2=='C'&&c1=='D')){
				s3=0;
				cout<<s1<<s2<<s3<<s4;
				return 0;
			}
//			cout<<c1-c2<<' '<<c2-c1<<endl;
			if(c1-c2==1||c2-c1==1){
				s4=1;
				cout<<s1<<s2<<s3<<s4;
				return 0;
			}
		}
		else s3=0;
	}
	else s3=0;
	cout<<s1<<s2<<s3<<s4;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
