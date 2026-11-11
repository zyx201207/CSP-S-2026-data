#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int p,q,n,m,t,x,y;
	p=a[0]*10+a[1];
	q=c[0]*10+c[1];
	if(p!=q){
		cout<<"0000";
	}else{
		cout<<1;
		p=b[0]*10+b[1];
		q=d[0]*10+d[1];
		if(p!=q){
			cout<<"000";
		}else{
			cout<<1;
			if(b[2]=='D'){
				b[2]='G';
			}
			if(d[2]=='D'){
				d[2]='G';
			}
			p=int(d[2]);
			q=int(b[2]);
			if(max(p,q)-min(p,q)>=3){
				cout<<"00";
			}else{
				cout<<1;
				if(max(p,q)-min(p,q)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
