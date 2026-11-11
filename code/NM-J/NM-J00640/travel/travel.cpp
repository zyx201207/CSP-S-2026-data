#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int f1=0,f2=0,f3=0,f4=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		f1=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			f2=1;
			if(b[2]<='C'&&d[2]<='C'){
				f3=1;
				if(b[2]+1==d[2]||d[2]+1==b[2]){
					f4=1;
				}
			}else if(b[2]>='D'&&d[2]>='D'){
				f3=1;
				f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
