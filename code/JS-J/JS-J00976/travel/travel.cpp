#include <bits/stdc++.h>
using namespace std;

const int N=1;
int a,b,c,d;
string l1,l2;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>l1>>c>>l2;
	b=(l1[0]-'0')*10+(l1[1]-'0');
	e=l1[2];
	d=(l2[0]-'0')*10+(l2[1]-'0');
	f=l2[2];
	
	if (a==c) cout<<1;else cout<<0;
	if (a==c && b==d) cout<<1;else cout<<0;
	if (a==c && b==d && ((e>='A' && e<='C' && f>='A' && f<='C') || ((e=='D' || e=='F') && (f=='D' || f=='F')))){
		if ((e=='D' || e=='F') && (f=='D' || f=='F')) cout<<11;
		else if (e-f==1 || e-f==-1) cout<<11;
		else cout<<10;
		
	}else cout<<"00";
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
