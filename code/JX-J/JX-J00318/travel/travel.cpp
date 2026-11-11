#include<bits/stdc++.h>
#include<string>
using namespace std;
string t,l,k;
int c[2],s[2];
int main(){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		cin>>t>>l;
		
		c[1]=t[0]*10+t[1];
		
		s[1]=l[0]*10+l[1];
		l=l[2];
		cin>>t>>k;
		c[2]=t[0]*10+t[1];
		s[2]=k[0]*10+k[1];
		k=k[2];
	
	if(c[1]==c[2]){
		cout<<1;
		if(s[1]==s[2]){
			cout<<1;
			if(((k=="A" || k=="B" || k=="C") &&  (l=="A" ||l=="B" || l=="C")) || ((k=="F" || k=="E") && (l=="F" || l=="E"))){
				cout<<1;
				if((k=="A" && l=="C") || (k=="C" && l=="A")){
					cout<<0;
					return 0;
					}else cout<<1; 
				}else cout<<0<<0;return 0; 
			}else cout<<0<<0<<0; return 0;
		}else cout<<0<<0<<0<<0;return 0;
	return 0;
}
