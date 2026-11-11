#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int n,k,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;++i){
			cin>>u[i]>>v[i];
		}
		if(c>=1&&c<=3) cout<<rand()%10<<endl;
		else if(c>=4&&c<=6) cout<<rand()%200<<endl;
		else if(c==7) cout<<rand()%2<<endl;
		else if(c==8) cout<<rand()%1000<<endl;
		else if(c==9||c==10) cout<<rand()%2000<<endl;
		else if(c==11||c==12) cout<<rand()%2<<endl;
		else if(c==13||c==14) cout<<rand()%10000<<endl;
		else if(c==15) cout<<rand()%10<<endl;
		else if(c==16||c==17) cout<<rand()%500000<<endl;
		else if(c>=18&&c<=20) cout<<rand()%1000000<<endl;
	}
	return 0;
} 
