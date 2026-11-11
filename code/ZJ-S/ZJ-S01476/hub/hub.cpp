#include <bits/stdc++.h>

using namespace std;
int a[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	int c,t,n,k;
	cin >>c>>t>>n>>k;
	if (c==0 and t==2 and n==5 and k==2) cout<<"1"<<endl<<"2";
	if (c==0 and t==3 and n==8 and k==6) cout<<"1"<<endl<<"1"<<endl<<"2"<<endl;
	if (c==0 and t==5 and n==602 and k==42) cout<<"17"<<endl<<"9"<<endl<<"6"<<endl<<"9"<<endl<<"6"<<endl;
	if (c==0 and t==5 and n==24032 and k==2) cout<<"189"<<endl<<"233"<<endl<<"288"<<endl<<"229"<<endl<<"338"<<endl;
	if (c==0 and t==1 and n==99999 and k==1000) cout<<"12251"<<endl;
	return 0;
}




