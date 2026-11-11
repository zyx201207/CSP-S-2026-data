#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c && a!="17" && b!="17")cout<<1;
	else cout<<"0000";
	for(int i=0;i<b.size();i++){
		int flag=1;
		if(i<2){
			if(!(b[0]<'2' && d[0]<'2'&& b[i]==d[i]))flag=0;
		}
		if(flag==0){
			cout<<"000";
			break;
		}
		if(flag==1 && i==1) cout<<1;
		if(i==2){
	    	flag=0;
		    if(b[i]<='C' && d[i]<='C' && b[i]!=d[i]){
		    	cout<<1;
			    if(d[i]+1==b[i] || b[i]+1==d[i])cout<<1;
			    else cout<<0;
		    }
		}
		if(i==2){
			if(b[i]>'C' && d[i]>'C' && b[i]!=d[i] && flag!=0){
				cout<<1;
				if(d[i]+1==b[i] || b[i]+1==d[i])cout<<1;
				else cout<<0;
			}
		}
		
	}
return 0;
}
