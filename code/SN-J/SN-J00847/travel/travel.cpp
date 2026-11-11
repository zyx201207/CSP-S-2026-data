//牟镇嘉 SN-J00847 西安汇知中学 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
	cout<<1;
        if(b[0]*10+b[1]==c[0]*10+c[1]){
		cout<<1;
				if(b[3]<F&&b[3]>C&&c[3]<F&&c[3]>C){
				cout<<1;
				if(b[3]-c[3]==1&&b[3]!="D")cout<<1;
       			else if(c[3]-b[3]==1&&c[3]!="D")cout<<1;
	   			else cout<<0;}
	            else if(b[3]<D&&b[3]>A-1&&c[3]<D&&c[3]>A-1){
				cout<<1;
				if(b[3]-c[3]==1&&b[3]!="D")cout<<1;
       			else if(c[3]-b[3]==1&&c[3]!="D")cout<<1;
	   			else cout<<0}
		        else cout<<0<<0;}
		else cout<<0<<0<<0;}
	else cout<<0<<0<<0<<0;

	return 0;
}
