#include<bits/stdc++.h>
using namespace std;
const long long wweerr=2e5+5;
const long long wwww=1e9+7;
char tong[wwww];
char jizimu[wweerr];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	long long x;
	char c;
	long long cnt=0;
	long long cntz=0;
	char q;
	char h;
	for(long long i=1;i<=n;i++){
		cin>>x;
		cin>>c;
		tong[cnt]=c;
		jizimu[++cntz]=c;
		h=c;
		cnt+=x;
	}
	q=tong[0];
	long long cntt=0;
	for(long long i=1;i<=cnt/2;i++){
		if(tong[i]!=' '){
			q=tong[i];
		}
		if(tong[cnt-i+1]!=' '){
			h=jizimu[--cntz];
		}
		if(q!=h){
			cntt++;
		}
	}
	cout<<cntt;
	return 0;
} 

