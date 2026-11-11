#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	for(int i=1;i<=4;i++){
		cin>>c1>>s1>>c2>>s2;
			if(c1==c2&&s1==s2){
				bool c1=true,c2=true,s1=true,s2=true;
				cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2;
			}else if(c1!=c2&&s1==s2){
				bool c1=false,c2=false,s1=false,s2=false;
				cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2;
			}else if(c1==c2&&s1!=s2){
				bool s1=false,s2=false,c1=true,c2=true;
				cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2;
			}else if(c1!=c2&&s1!=s2){
				bool s1=false,s2=false,c1=false,c2=false;
				cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2;
		} 
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
