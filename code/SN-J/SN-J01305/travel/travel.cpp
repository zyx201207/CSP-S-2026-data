#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct A{
	string c,s;
};
A r,x;
int sum=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.c>>r.s>>x.c>>x.s;
	if(r.c==x.c){
		cout<<1;
	}else{
		cout<<0;
		sum=0;
	}
	char a,b;
	a=r.s[2];
	b=x.s[2];
	if(sum==0){
		cout<<0;
	}else{
		int f=1;
		for(int i=0;i<2;i++){
			if(r.s[i]!=x.s[i]){
				cout<<0;
				f=0;
				sum=0;
				break;
			}
		}
		if(f==1){
			cout<<1;
		}
	}
	if(sum==0){
		cout<<0;
	}else{
		if((a<='C'&&a>='A'&&b<='E'&&b>='D')||(b<='C'&&b>='A'&&a<='E'&&a>='D')){
			cout<<0;
			sum=0;
		}else{
			cout<<1;
		}
	}
	if(sum==0){
		cout<<0;
	}else{
		if(a==b-1&&b!='D'){
			cout<<1;
		}else cout<<0;sum=0;
	}
	return 0;
}
