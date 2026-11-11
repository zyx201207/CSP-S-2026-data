#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=2,b=2,c=2,d=2;
	if(c1!="16"&&c1!="01"&&c2!="16"&&c2!="01")
	{
		if(c1==c2){
			a=1;
			for(int i=0;i<=s1.size();i++){
				if(s1[i]==s2[i]){
					b=1;
				}
				else{
					b=0;
					break;
				}
			}
			for(int i=s1.size()-1;i>s1.size()-2;i--){
				if(s1[i]<='C'&&s2[i]<='C'){
					c=1;
					break;
				}
				else if(s1[i]>='D'&&s2[i]>='D'){
					c=1;
					break;
				}
				else{
					c=0;
					break;
				}
			}
			for(int i=s1.size()-1;i>=s1.size()-2;i--){
				if((s1[i]>='A'&&s1[i]<'B'&&s2[i]>='B'&&s2[i]<'C') || (s1[i]>='B'&&s1[i]<'C'&&s2[i]>='C'&&s2[i]<'D') || (s2[i]>='A'&&s2[i]<'B'&&s1[i]>='B'&&s1[i]<'C') || (s2[i]>='B'&&s2[i]<'C'&&s1[i]>='C'&&s1[i]<'D')){
					d=1;
					break;
				}
				else d=0;
				if((s1[i]=='D'&&s2[i]=='F')||(s1[i]=='F'&&s2[i]=='D')){
					d=1;
					break;
				}
				else d=0;
			}
		}
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
