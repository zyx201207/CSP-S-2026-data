#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long lena,lenb,lenc,lend;
long long f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>a>>b>>c>>d;
	lena=a.size();
	lenb=b.size();
	lenc=c.size();
	lend=d.size();
	if(lena==lenc){
		for(int i=0;i<lena;i++){
			if(a[i]!=c[i]){
				f=1;
				break;
			}
		}
	}
	if(b[2]=='D')b[2]='E';
	if(d[2]=='D')d[2]='E';
	if(f)cout<<"0";
	else cout<<"1";
	for(int i=0;i<2;i++){
		if(b[i]!=d[i])f=1;
	}
	if(f)cout<<"0";
	else cout<<"1";
	if(f==0){
		if(b[2]>'C'&&d[2]<='C'){
			f=1;
		}
		if(b[2]<='C'&&d[2]>'C'){
			f=1;
		}
		if(b[0]!=d[0]||b[1]!=d[1]){
			f=1;
		}
	}
	if(f)cout<<"0";
	else cout<<"1";
	if(f==0&&b[0]==d[0]&&b[1]==d[1]&&abs(int(b[2]-d[2]))==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
