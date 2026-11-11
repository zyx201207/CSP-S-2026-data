#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)cout<<1;
		else {
			cout<<"0000";
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	char s3=c[2],s4=d[2];
	if(c[0]==d[0]&&c[1]==d[1])cout<<1;
		else {
			cout<<"000";
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	if(max(s3,s4)<='C'||min(s3,s4)>='D')cout<<1;
		else {
			cout<<"00";
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	if(abs(s3-s4)==1)cout<<1;
		else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
