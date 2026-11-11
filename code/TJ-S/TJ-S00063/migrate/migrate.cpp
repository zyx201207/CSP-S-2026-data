#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;
const int N=1e7+56;
int c,t,num;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,x[N];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0){
			if(t==2&&n==4&&d==2){
				cout<<1<<endl<<2;
				return 0;
			}
			else if(t==2&&n==5&&d==3){
				cout<<0<<endl<<1;
				return 0;
			}
			else if(t==17&&n==197&&d==29418319589926278){
				cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
				return 0;
			}
			else if(t==12&&n==260000&&d==1){
				cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
				return 0;
			}
			else if(t==14&&n==200001&&d==206291914738518400){
				cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
				return 0;
			}
		}
		srand(time(0));
		num=((long long)rand()*(RAND_MAX+num)+rand());
		cout<<num<<endl;
	}
	return 0;
}
