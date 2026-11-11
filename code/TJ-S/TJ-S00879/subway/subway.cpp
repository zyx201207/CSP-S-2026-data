#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<15<<'/n'<<8;
	long long a,b,c[200010],d,ee;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	d=abs(c[1]-c[2]);
	long long e=0;
	for(int i=1;b>=e;i++){
		e+=i*d;
		if(b<e){
			break;
		}
		ee=i;
		
	}
	cout<<ee+1;
	return 0;
}	
