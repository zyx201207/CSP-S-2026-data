#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string t1="",t2="";
	cin >> a >> b >> c >> d;
	//1
	if(a==c) cout << 1;
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	//2
	for(int i=0;i<b.size();i++){
		if(b[i]>='0' && b[i]<='9') t1+=b[i];
	}
	for(int i=0;i<d.size();i++){
		if(d[i]>='0' && d[i]<='9') t2+=d[i];
	}
	if(t1==t2) cout << 1;
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	//3
	int n1=b.size(),n2=d.size();
	char c1=b[n1-1];
	char c2=d[n2-1];
	if((c1=='A' or c1=='B' or c1=='C') && (c2=='A' or c2=='B' or c2=='C')) cout << 1;
	else if((c1=='D' or c1=='F') && (c2=='D' or c2=='F')) cout << 1;
	else cout << 0;
	//4
	if(c1=='A' && c2=='B') cout << 1;
	else if(c1=='B' && c2=='A') cout << 1;
	else if(c1=='B' && c2=='C') cout << 1;
	else if(c1=='C' && c2=='B') cout << 1;
	else if(c1=='D' && c2=='F') cout << 1;
	else if(c1=='F' && c2=='D') cout << 1;
	else cout << 0;
}
