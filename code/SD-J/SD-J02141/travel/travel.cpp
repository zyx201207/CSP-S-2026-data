#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,a[5],b[5],c,d,e,f,g,h,x;
	cin>>c1>>c2>>s1>>s2;
	c2=a[5];
	s2=b[5];
	a[3]=d or e or f or g or h; 
	b[3]=d or e or f or g or h;
	
	if(c1==s1){
		cout<<"0";
	}else{
		cout<<"1";
	}
	if(c1!=s1){
		if(a[1]==b[1]||a[2]==a[2]){
			c=1;
			cout<<"1";
		}else{
			c=0;
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(c==1){
		if(a[3]==d or e or f || b[3]==d or e or f || a[3]==g or h||b[3]==g or h){
			x=1;
			cout<<"1";
		}
	}else{
		x=0;
		cout<<"0";
	}
	if(x=1){
		if(a[3]==d||b[3]==e or a[3]==e||b[3]==d or a[3]==e||b[3]==f or a[3]==f||b[3]==e or a[3]==g||b[3]==h or a[3]==h||b[3]==g ){
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	
	fclose(stdin);
	fclose(stdout);                                                     
	return 0;
}
