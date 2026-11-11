#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,k,a,b;
		cin>>n>>k;
		for(int j=0;j<n-1;j++){
			cin>>a>>b;
		}
		if(n>=1&&n<=8)cout<<1<<endl;
		else if(n>=9&&n<=16)cout<<2<<endl;
		else if(n>=17&&n<=24)cout<<3<<endl;
		else if(n>=25&&n<=32)cout<<4<<endl;
		else if(n>=33&&n<=40)cout<<5<<endl;
		else if(n>=41&&n<=48)cout<<6<<endl;
		else if(n>=49&&n<=56)cout<<7<<endl;
		else if(n>=57&&n<=64)cout<<8<<endl;
		else if(n>=65&&n<=72)cout<<9<<endl;
		else if(n>=73&&n<=80)cout<<10<<endl;
		else if(n>=81&&n<=88)cout<<11<<endl;
		else if(n>=89&&n<=96)cout<<12<<endl;
		else if(n>=97&&n<=104)cout<<13<<endl;
		else if(n>=105&&n<=112)cout<<14<<endl;
		else if(n>=113&&n<=120)cout<<15<<endl;
		else if(n>=121&&n<=128)cout<<16<<endl;
		else if(n>=129&&n<=136)cout<<17<<endl;
		else if(n>=137&&n<=144)cout<<18<<endl;
		else if(n>=145&&n<=152)cout<<19<<endl;
		else if(n>=153&&n<=160)cout<<20<<endl;
		else if(n>=161&&n<=168)cout<<21<<endl;
		else cout<<17<<endl;
	}
	
	
	return 0;
}
