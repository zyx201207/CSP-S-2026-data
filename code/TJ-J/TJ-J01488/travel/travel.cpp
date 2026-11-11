#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d; 
	cin>>a>>b>>c>>d;
	bool x=1;
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]!=c[i]){
			x=0;
		}
	}
	cout<<x;
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i]){
			x=0;
		}
	}
	cout<<x;
	for(int i=2;i<=b.size()-1;i++){
		if(b[i]>='A'&&b[i]<='Z'){
			if(b[i]=='D'&&d[i]=='C'||b[i]=='C'&&d[i]=='D'||b[i]=='D'&&d[i]!='F'||b[i]=='F'&&d[i]!='D'||b[i]!='D'&&d[i]=='F'||b[i]!='F'&&d[i]=='D'){
				x=0;
			}
		}
		cout<<x;
		if(b[i]>='A'&&b[i]<='Z'){
			if(b[i]=='D'&&d[i]=='C'||b[i]=='C'&&d[i]=='D'){
				x=0;
			}
			else if(b[i]=='D'&&d[i]=='F'&&x==1||b[i]=='D'&&d[i]=='F'&&x==1){
				x=1;
			}
			else if(b[i]+1!=d[i]&&d[i]+1!=b[i]){
				x=0;
			}
		}
		cout<<x;
	}
	return 0;
}
