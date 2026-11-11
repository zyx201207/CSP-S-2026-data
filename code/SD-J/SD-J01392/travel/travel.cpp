#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1;
	int a=0,b=0,c=0,d=0,c1=0,d1=0;
	cin>>a>>a1>>b>>b1;
	for(int i = 1;i<=a1.size();i++){
		if('0'<=a1[i-1]&&a1[i-1]<='9'){
			int x=(int)a1[i-1]-'0';
			c*=10;
			c+=x;
		}else {
			c1=(int)a1[i-1]-'A'+1;
		}
	}
	for(int i = 1;i<=b1.size();i++){
		if('0'<=b1[i-1]&&b1[i-1]<='9'){
			int x=(int)b1[i-1]-'0';
			d*=10;
			d+=x;
		}else {
			d1=(int)b1[i-1]-'A'+1;
		}
	}
//	cout<<c1<<" "<<d1<<endl;
	if(a!=b){
		cout<<"0000\n";
		return 0;
	}else{
		cout<<"1";
	}
	if(c!=d){
		cout<<"000\n";
		return 0;
	}else {
		cout<<"1";
	}
	if((d1<=3&&c1<=3)||(c1>3&&d1>3)){
		cout<<"1";
	}else{
		cout<<"00\n";
		return 0;
	}
	if(abs(c1-d1)==1){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}
