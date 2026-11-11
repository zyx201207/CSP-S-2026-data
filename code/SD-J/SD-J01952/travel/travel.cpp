#include <bits/stdc++.h>
using namespace std;
string A,B;
long long a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>A>>b>>B;
	c=A[1]-'0'+(A[0]-'0')*10;
	d=B[1]-'0'+(B[0]-'0')*10;
	e=A[2]<'D';
	f=B[2]<'D';
	if(a!=b)cout<<"0000";
	else{
		cout<<1; 
		if(c!=d)cout<<"000";
		else{
			cout<<"1";
			if(e!=f)cout<<"00";
			else{
				cout<<"1";
				if(A[2]+1==B[2]||B[2]+1==A[2])cout<<1;
				else cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
