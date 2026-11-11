#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>c>>m>>b>>d;
	if(n!=m) cout<<"0000";
	else{
		cout<<"1";
		if(a!=b) cout<<"000";
		else{
			cout<<"1";
		    if((c=='A'&&d=='D')||(c=='A'&&d=='F')||(c=='B'&&d=='D')
	        ||(c=='B'&&d=='F')||(c=='C'&&d=='D')||(c=='C'&&d=='F')
	        ||(c=='D'&&d=='A')||(c=='D'&&d=='B')||(c=='D'&&d=='C')
	        ||(c=='F'&&d=='A')||(c=='F'&&d=='B')||(c=='F'&&d=='C'))
	            cout<<"00";
	        else if((c=='A'&&d=='C')||(c=='C'&&d=='A'))
		        cout<<"10";
	    else cout<<"11";
		}
	}
	return 0;
}