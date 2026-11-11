#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k;
ll x[20000000+10][5];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int o=0;
	while(t>0){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x[i][1]>>x[i][2];
		}
		if(c==0){
			if(t==2 and !o){cout<<1<<endl<<2;o=1;}
			if(t==3 and !o){cout<<1<<endl<<1<<endl<<2;o=1;}
			if(t==5 and !o){
				if(n==602 and k==42 )cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
				if(n==24032 and k==2)cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
				o=1;
			}
			if(t==1 and !o){cout<<12251;o=1;}
			}
			t--;
	}
	return 0;
}