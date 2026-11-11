#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	int ss=b[2],vv=d[2];
	int aa=0;
	for(int i=0;i<a.size();i++){
		aa+=a[i]-'0';
	}
	int cc=0;
	for(int i=0;i<c.size();i++){
		cc+=c[i]-'0';
	}
	int bb=0;
	for(int i=0;i<b.size()-1;i++){
		bb+=b[i]-'0';
	}
	int dd=0;
	for(int i=0;i<d.size()-1;i++){
		dd+=d[i]-'0';
	}
	if(aa==cc){
		cout<<1;
		if(bb==dd){
			cout<<1;
			if((ss<=67&&vv<=67)||(ss>=68&&vv>=68)){
				cout<<1;
				if(ss+1==vv||ss-1==vv){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
