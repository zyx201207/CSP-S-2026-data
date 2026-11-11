#include<bits/stdc++.h>
using namespace std;
string a1,a2,a3,a4;
int f1,f2,f3,f4;
bool pd2(string a,string b){
	string c,d;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			c+=a[i];
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9'){
			d+=b[i];
		}
	}
	return c==d;
}
bool pd3(string a,string b){
	string c,d;
	for(int i=0;i<a.size();i++){
		if(a[i]>='A'&&a[i]<='F'){
			c+=a[i];
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]>='A'&&b[i]<='F'){
			d+=b[i];
		}
	}
	if((c=="C"&&d=="D")||(c=="D"&&d=="C")){
		return 0;
	}else{
		return 1;
	}
}
bool pd4(string a,string b){
	string c,d;
	for(int i=0;i<a.size();i++){
		if(a[i]>='A'&&a[i]<='F'){
			c+=a[i];
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]>='A'&&b[i]<='F'){
			d+=b[i];
		}
	}
	if(c=="A"&&d=="B")return 1;
	if(c=="B"&&d=="C")return 1;
	if(c=="D"&&d=="F")return 1;
	if(d=="A"&&c=="B")return 1;
	if(d=="B"&&c=="C")return 1;
	if(d=="D"&&c=="F")return 1;
	return 0;
}
int main()
{   freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a3>>a4;
    if(a1==a3){
    	cout<<1;
    	f1=1;
	}else{
		cout<<0;
	}
	if(pd2(a2,a4)&&f1==1){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	if(pd3(a2,a4)&&f2==1){
		cout<<1;
		f3=1;
	}else{
		cout<<0;
	}
	if(pd4(a2,a4)&&f3==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
