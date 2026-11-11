#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,s,a1,s1,s2,a2;
	char c,c1,c2;
	cin>>n>>a>>c;
	if(n==1){
		s=0;
	    cout<<s;	
	}
	if(n==2){
		cin>>a1>>c1;
		if(c==c1){
			s1=0;
		    cout<<s1;
		}
		else{
			if(a>a1){
				cout<<a1;
			}
			else{
				cout<<a;
			}
		}
	}
	if(n==3){
		cin>>a1>>c1;
		cin>>a2>>c2;
		if(c==c1==c2){
			s2=0;
		    cout<<s2;
		}
	}
	return 0;
}