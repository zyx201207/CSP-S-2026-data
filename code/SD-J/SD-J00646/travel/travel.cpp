#include<bits/stdc++.h>
using namespace std;
char t,p1,p2,e;
int s1,s2,t1,t2;
bool d1=false,d2=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=2;i++){
		cin>>t;
		int a=(t-'0');
		t1=t1*10+a;
	}
	
	for(int i=1;i<=2;i++){
		cin>>t;
		int a=(t-'0');
		s1=s1*10+a;
	}cin>>p1;
	if(p1=='A'||p1=='B'||p1=='C')d1=true;
	for(int i=1;i<=2;i++){
		cin>>t;
		int a=(t-'0');
		t2=t2*10+a;
	}
	for(int i=1;i<=2;i++){
		cin>>t;
		int a=(t-'0');
		s2=s2*10+a;
	}cin>>p2;
	if(p2=='A'||p2=='B'||p2=='C')d2=true;
	//
	if(t1==t2)cout<<1;
	else cout<<0;
	if(s1==s2&&t1==t2)cout<<1;
	else cout<<0;
	if(d1==d2&&s1==s2&&t1==t2)cout<<1;
	else cout<<0;
	if(d1==d2&&s1==s2&&t1==t2&&(p1+1==p2||p2+1==p1))cout<<1;
	else cout<<0;
//	cout<<endl<<t1<<" "<<t2<<" "<<s1<<" "<<s2<<" "<<d1<<" "<<d2;
	return 0;
} 
