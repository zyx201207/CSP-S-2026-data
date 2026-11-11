#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("treval.in","r",stdin);
	freopen("treval.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
	  cout<<1;
	  if(b[0]==d[0]&&b[1]==d[1]){
	     cout<<1;
	     if(b[2]=='F'||b[2]=='D'){
	        if(d[2]=='F'||d[2]=='D'){
	        cout<<1<<1;
	        }
	     }
	     else{
	        if(((b[2]=='D'||b[2]=='F')&&(d[2]!='D'||d[2]!='F'))||((d[2]=='D'||d[2]=='F')&&(b[2]!='D'||b[2]!='F'))){
				cout<<0<<0;
			}
			else{
				cout<<1;
				if(b[2]==d[2]-1||b[2]==d[2]+1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
	     }
	  }
	  else{
	     cout<<0<<0<<0;
	  }
	}
	else{
	  cout<<0<<0<<0<<0;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
