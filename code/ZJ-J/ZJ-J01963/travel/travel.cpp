#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool t=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a>>b>>c>>d;
	int lenb=b.size();
	char bb=b[lenb-1],dd=d[lenb-1];
	if(a==c){
	    cout<<'1';
	    for(int i=0;i<lenb-1;i++){
		    if(b[i]!=d[i]){
			    t=0;
			    cout<<"000";
		    }
	    }
	    if(t){ 
	        cout<<'1';
	        if((bb<='C'&&dd<='C')||(bb>='D'&&dd>='D')){
	        	cout<<'1';
	        	if((bb>='D'&&dd>='C')||(bb<='C'&&dd<='C')&&abs(bb-dd)==1){
	        		cout<<'1';
				}
				else cout<<'0';
			}
			else cout<<"00";
	    }
	}
	else{
		cout<<"0000";
	}
	return 0;
}