#include <bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb;

int main()

{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>cb>>sa>>sb;
	if(ca!=sa)
	{
		cout <<"0000";
		return 0;
	}
	else
		cout <<"1";
 	if (cb[0]==sb[0] && cb[1]==sb[1])
	 {
	 	cout <<'1';
	 	if(cb[2]=='A' || cb[2]=='B' || cb[2]=='C' ) 
	 	{
	 		if(sb[2]=='A' || sb[2]=='B' || sb[2]=='C' ) 
	 		{
	 			cout <<'1';
	 			if(cb[2]=='A' && sb[2]=='B') cout <<'1'; 
	 			else if(cb[2]=='B' && sb[2]=='A' || sb[2]=='C') cout <<'1'; 
	 			else if(cb[2]=='C' && sb[2]=='B' ) cout <<'1';
	 			else cout<<'0';
			 }
			else cout <<"00";
	 		
		 }
		else if(cb[2]=='D' || cb[2]=='F') 
		{
			if(sb[2]=='D' || sb[2]=='F')
			{
				cout <<'1';
				if (cb[2]=='D' && sb[2]=='F') cout <<'1';
				else if (cb[2]=='F' && sb[2]=='D') cout <<'1';
				else cout<<'0';
			 } 
			else cout <<"00";	 		
		}
	 	
	  } 
 	else cout<<"000";
 	
 	
	

	
	return 0;
}
