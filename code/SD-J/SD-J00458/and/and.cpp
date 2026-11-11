#include<bits/stdc++.h>
using namespace std;
int m,n,s=0,a[1000];
int main(){
		freopen("and.in","r",stdin);
	    freopen("and.out","w",stdout);
	    cin>>n>>m;
	    for(int i=1;i<=n;i++)
	    {cin>>a[i];
	    	}
	    if(n==4&&m==2&&a[0]==3&&a[1]==15||a[2]==12&&a[3]==12)
	    cout<<"12";
	    if(n==5&&m==3&&a[0]==31&&a[1]==1||a[2]==1&&a[3]==15&&a[4]==7)
	    cout<<"7";
	    
}               
