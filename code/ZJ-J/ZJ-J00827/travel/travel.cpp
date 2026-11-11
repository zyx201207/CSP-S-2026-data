#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
int x,y,z,w,f1,f2,f3,f4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=stoi(a),y=stoi(c);
	if(x==y){
		f1=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[0]+b[1]==d[0]+d[1] && f1){
		f2=1;
		cout<<1;
	}else{
		cout<<0;
	}
	char s1=b[2],s2=d[2];
//	cout<<'\n'<<s1<<' '<<s2<<'\n';
			if((f1 && f2) && ((s1>='A' && s1<='C' && s2>='A' && s2<='C') || (s1>='D' && s1<='E' && s2>='D' && s2<='E'))){
				f3=1;
				cout<<1;
			}else{
				cout<<0;
			}
	if(s1>s2) swap(s1,s2);
	if(s2-s1==1 && (s2!='D' && s1!='C') && (f3 && f2 && f1)){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
