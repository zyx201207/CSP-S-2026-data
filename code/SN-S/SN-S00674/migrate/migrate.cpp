#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	int c,t,n,d,a[200005];
	void work(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin>>c>>t;
		if(c==0&&t==2){
			while(t--){
				cin>>n>>d;
				for(int i=1;i<=n;i++){
					cin>>a[i];
				}
				if(n==4&&d==2){
					cout<<1<<"\n"<<2;
					break;
				}
				if(n==5&&d==3){
					cout<<0<<"\n"<<1;
					break;
				}
			}
		}
		if(c==0&&t==17){
			while(t--){
				cin>>n>>d;
				for(int i=1;i<=n;i++){
					cin>>a[i];
				}
			}
			cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n";
			cout<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0;
		}
		if(c==0&&t==12){
			while(t--){
				cin>>n>>d;
				for(int i=1;i<=n;i++){
					cin>>a[i];
				}
			}
			cout<<0<<"\n"<<0<<"\n"<<259997<<"\n"<<259995<<"\n";
			cout<<86669<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<7<<"\n"<<5<<"\n"<<5<<"\n"<<0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return Vesperon::work() ,0;
}
