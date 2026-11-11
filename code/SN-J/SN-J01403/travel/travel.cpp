#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string sum,a[15],s1,s2,b,c;
int main(){
//  freopen("travel.in","r",stdin);
//  freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2)
	{
		cout<<"0000";
		return 0;	
	}
	if(c1==c2)
	{
	    for (int i=1;i<=18;i++)
    	{
	    	for (int j=0;j<=4;j++)
	    	{
	    		a[0]="A";
	            a[1]="B";
            	a[2]="C";
            	a[3]="D"; 
	            a[4]="E";
	    		a[j]=i+a[j];
	    		a[j+1]=i+a[j+1];
			    b=a[j];
	    		c=a[j+1];
	    	    if (b==s1&&c==s2)
	    	    {
    		    	sum+="1";
    			}
    		}
    	}
    }
	cout<<sum;
	return 0;
}
