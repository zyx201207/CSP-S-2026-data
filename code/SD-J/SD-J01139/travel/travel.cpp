#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> x >> b >> y;
	int xx=(x[0]-'0')*10+x[1]-'0',yy=(y[0]-'0')*10+y[1]-'0';
	if(a==b)cout << 1;
	else cout << 0;
	if(a==b&&xx==yy)cout << 1;
	else cout << 0;
	if(a==b&&xx==yy&&(x[2]=='A'&&y[2]=='B'||y[2]=='A'&&x[2]=='B'))cout << 1;
	else if(a==b&&xx==yy&&(x[2]=='A'&&y[2]=='C'||y[2]=='A'&&x[2]=='C'))cout << 1;
	else if(a==b&&xx==yy&&(x[2]=='B'&&y[2]=='C'||y[2]=='B'&&x[2]=='C'))cout << 1;
	else if(a==b&&xx==yy&&(x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F'))cout << 1;
	else cout << 0;
	
	if(a==b&&xx==yy&&(x[2]=='A'&&y[2]=='B'||y[2]=='A'&&x[2]=='B')){
		if(a==b&&xx==yy&&x[2]=='A'&&y[2]=='B'||y[2]=='A'&&x[2]=='B')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='B'&&y[2]=='C'||y[2]=='B'&&x[2]=='C')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F')cout << 1;
		else cout << 0;
	}
	else if(a==b&&xx==yy&&(x[2]=='A'&&y[2]=='C'||y[2]=='A'&&x[2]=='C')){
		if(a==b&&xx==yy&&x[2]=='A'&&y[2]=='B'||y[2]=='A'&&x[2]=='B')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='B'&&y[2]=='C'||y[2]=='B'&&x[2]=='C')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F')cout << 1;
		else cout << 0;
	}
	else if(a==b&&xx==yy&&(x[2]=='B'&&y[2]=='C'||y[2]=='B'&&x[2]=='C')){
		if(a==b&&xx==yy&&x[2]=='A'&&y[2]=='B'||y[2]=='A'&&x[2]=='B')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='B'&&y[2]=='C'||y[2]=='B'&&x[2]=='C')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F')cout << 1;
		else cout << 0;
	}
	else if(a==b&&xx==yy&&(x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F')){
		if(a==b&&xx==yy&&x[2]=='A'&&y[2]=='B'||y[2]=='A'&&x[2]=='B')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='B'&&y[2]=='C'||y[2]=='B'&&x[2]=='C')cout << 1;
		else if(a==b&&xx==yy&&x[2]=='D'&&y[2]=='F'||y[2]=='D'&&x[2]=='F')cout << 1;
		else cout << 0;
	}
	else cout << 0;
	
	
	return 0;
} 
