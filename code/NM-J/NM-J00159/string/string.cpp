#include<bits/stdc++.h>
using namespace std;
string c,q,h;
char z;
int a,b,js=0,d;
int main(){
        freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
cin>>a;
for(int i=0;i<a;i++){
	cin>>b>>z;
	
	for(int j=0;j<b;j++){
		c[j+js]=z;
	}js+=b;
	

}
//cout<<js;
for(int i=0;i<js/2;i++){
	if(c[js-i]!=c[i])d++;
}
cout<<d;
return 0;
fclose(stdin);
fclose(stdout);
}
