#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	string a,b;
	cin>>c1>>s1>>a>>c2>>s2>>b;
		if(c1==c2){
			cout<<1;
		}else{
			cout<<0;
		}
	    if(c1==c2&&s1==s2){
	    	cout<<1;
		}else{
			cout<<0;
		}
		if(c1==c2 && s1==s2 && a=="A" || a=="B" || a=="C" && b=="A" || b=="B" || b=="C"){
			    cout<<1;
			}else if(c1==c2 && s1==s2 && a=="D" || a=="F" && b=="D" && b=="F"){
				cout<<1;
			}else{
				cout<<0;
			}
		if(c1==c2&&s1==s2 && a=="A"&&b=="B" || a=="B"&&b=="C" || a=="D"&&b=="F" || b=="A"&&a=="B" || b=="B"&&a=="C" || b=="D"&&a=="F"){
			cout<<1;
		}else{
			cout<<0;
		}
			
	return 0;
}														
