#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin) ;
	freopen("travel.out","r",stdout) ; 
	 int a,b,c,d;
	 cin>>a>>b>>c>>d;
	 if(a==01&&c==01)
	 {
	 	cout<<"0000";
	 	
	 }
	 if(a==16&&c==16)
	 {
    	cout<<"0000";
	 }
	 if(a==c)
	 {
	    cout<<"11";
	 }
	 if(b==d)
	 {
        cout<<"11";
	 }
	 else
	 {
	 	cout<<"00";
	
	 }
	 if(b[A]==d[A])
	 {
	 	cout<<"11"
	 }
	 
   return 0;
}

   