#include<bits/stdc++.h>
using namespace std;
string s1,s2;
struct node{
	int cxh,zwp;
	char zwz;
};
node r,x;
bool check(){
	bool a[10];
	if(r.zwz=='A'||x.zwz=='A') a[1]=true;
	if(r.zwz=='B'||x.zwz=='B') a[2]=true;
	if(r.zwz=='C'||x.zwz=='C') a[3]=true;
	if(r.zwz=='D'||x.zwz=='D') a[4]=true;
	if(r.zwz=='E'||x.zwz=='E') a[5]=true;
	if((a[1]&&a[2])||(a[2]&&a[3])||(a[4]&&a[5])) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.cxh>>r.zwp>>r.zwz>>x.cxh>>x.zwp>>x.zwz;
	if(r.cxh==x.cxh){
		cout<<1;
		if(r.zwp==x.zwp){
			cout<<1;
			bool rr=false,xx=false;
			if(r.zwz=='A'||r.zwz=='B'||r.zwz=='C') rr=true;
			if(x.zwz=='A'||x.zwz=='B'||x.zwz=='C') xx=true;
			if(rr==xx){
				cout<<1;
				if(check()) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}