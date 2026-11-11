#include<bits/stdc++.h>
using namespace std;
int a,a1,b,b1;
int a2,b2;
string c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c;
	for(int i=0;i<3;i++){
		if(c[i]>='0'&&c[i]<='9')a1=a1*10+c[i]-'0';
		else a2=(c[i]-64);
	}
	cin>>b>>c;
	for(int i=0;i<3;i++){
		if(c[i]>='0'&&c[i]<='9')b1=b1*10+c[i]-'0';
		else b2=(c[i]-64);
	}
	if(a==b)cout<<1;
	else cout<<0;
	if(a==b&&a1==b1)cout<<1;
	else cout<<0;
	bool f=0;
	if(a==b&&a1==b1&&abs(a2-b2)==1&&!((a2==3&&b2==4)||(a2==4&&b2==3))){
		f=1;
	}
	if(f){
		cout<<1;
	}else{
		if((a==b&&a1==b1&&a2==1&&b2==3)||(a==b&&a1==b1&&a2==3&&b2==1)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(f)cout<<1;
	else cout<<0;
	return 0;
}
