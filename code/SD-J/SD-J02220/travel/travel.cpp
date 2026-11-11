#include<iostream>
#include<string>
using namespace std;
string a,b,c,d,ls;
bool f1,f2,f3,f4;
int sj(string j1){
	char j8=j1[2];
	switch(j8){
		case 'A':return 1;
		case 'B':return 2;
		case 'C':return 3;
		case '\0':return 4;
		case 'D':return 5;
		case 'F':return 6;
	}
}
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
		f1=true;
//		cout<<b[0]<<d[0]<<b[1]<<d[1];
		if(b[0]==d[0]&&b[1]==d[1]){
			f2=true;
			if((sj(b)>4&&sj(d)>4)||(sj(b)<4&&sj(d)<4)){
				f3=true;
				if(sj(b)-sj(d)==1||sj(b)-sj(d)==-1){
					f4=true;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4<<endl;
	return 0;
}

