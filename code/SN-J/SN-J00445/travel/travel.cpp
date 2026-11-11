#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
		cout<<1;
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    cout<<1;
		    if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>3&&s2[2]-'A'>3)){
				cout<<1;
				if(s1[2]-'A'<=2) p1=s1[2]-'A';
			    else if(s1[2]-'A'==3) p1=4;
			    else p1=5;
				if(s2[2]-'A'<=2) p2=s2[2]-'A';
			    else if(s2[2]-'A'==3) p2=4;
			    else p2=5;
			    if(p1-p2==1||p2-p1==1) cout<<1;
			    else cout<<0;
			}else cout<<0<<0;
	    }else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
