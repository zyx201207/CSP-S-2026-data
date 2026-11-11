#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1>>c2>>s2;
	if(c1==c2){
	    ans+="1";
	    if(s1[0]==s2[0]&&s1[1]==s2[1])
	    {
	    	ans+="1";
	    	if((s1[2]<='C' && s2[2]<='C')||(s1[2]>='D' && s2[2]>='D')){
	    		ans+="1";
	    		int a=s1[2];
	    		int b=s2[2];
	    		if(s1[2]<='C'){
	    		    if(a-b==1||b-a==1)
	    		    {
	    		    	ans+="1";
				    }
				    else ans+="0";
			    }
				else if(s1[2]>='D')
				{
					if(a-b==2||b-a==2)ans+="1";
					else ans+="0";
				}
			}
			else{
				ans+="0";
				ans+="0";
			}
		}
		else{
			ans+="000";
		}
    }
	else {
	    ans+="0000";
    }
	cout << ans;
	return 0;
}
