#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    int b,c,d,e,f;
    int m;
    cin>>n>>m;
    int a[n];
    int i=0;i<=n;i++;
    {
	cin>>a[i+1];
	if(a[i+1]==1){
        b=0;
        b+=1;
	}
	if(a[i+1]==2){
        c=0;
        c+=1;
	}
	if(a[i+1]==3){
        c=0;
        c+=1;
	}
	if(a[i+1]==4){
        d=0;
        d+=1;
	}
	if(a[i+2]==1){
        b=0;
        b+=1;
	}
	if(a[i+2]==2){
        c=0;
        c+=1;
	}
	if(a[i+2]==3){
        c=0;
        c+=1;
	}
	if(a[i+2]==4){
        d=0;
        d+=1;
	}
	if(a[i+3]==1){
        b=0;
        b+=1;
	}
	if(a[i+3]==2){
        c=0;
        c+=1;
	}
	if(a[i+3]==3){
        c=0;
        c+=1;
	}
	if(a[i+3]==4){
        d=0;
        d+=1;
	}
	if(a[i+4]==1){
        b=0;
        b+=1;
	}
	if(a[i+4]==2){
        c=0;
        c+=1;
	}
	if(a[i+4]==3){
        c=0;
        c+=1;
	}
	if(a[i+4]==4){
        d=0;
        d+=1;
	}





    }

   cout<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" ";
   return 0;
}

