#include<bits/stdc++.h>
using namespace std;
#define ll long long
string q,w,e,r;ll t,y,a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>e>>r;
	t=(bool)(w[2]=='D'||w[2]=='F');y=(bool)(r[2]=='D'||r[2]=='F');
	if(w[2]=='F')a[4]=1;
	else a[w[2]-'A']=1;
	if(r[2]=='F')a[4]=1;
	else a[r[2]-'A']=1;
	cout<<(bool)(q==e)<<(bool)(q==e&&w.substr(0,2)==r.substr(0,2));
	cout<<(bool)(q==e&&w.substr(0,2)==r.substr(0,2)&&t==y);
	cout<<(bool)(q==e&&w.substr(0,2)==r.substr(0,2)&&t==y&&((a[0]&&a[1])||(a[1]&&a[2])||(a[3]&&a[4])));
	return 0;
}
