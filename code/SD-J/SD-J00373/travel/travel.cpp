#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool f1=0,f2=0,f3=0,f4=0;
	if(a1==b1){
		f1=1;
		char t1=a2[2],t2=b2[2];
		a2.erase(2,1);b2.erase(2,1);
		if(a2==b2){
			f2=1;
			if(t1<='C'&&t2<='C'||t1>='D'&&t2>='D'){
				f3=1;
				char q1=(char)t1-1;
				char q2=(char)t1+1;
				if(q1==t2&&t2!='C'||q2==t2&&t2!='D'){
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
