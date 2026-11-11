#include<iostream>
#define ll long long 
using namespace std;
long long t,n,d,a[15],c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<3){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(n<=3){
				cout<<0<<endl;
			}
			else if(n==4){
				if(a[4]-a[1]>d&&a[3]-a[1]<=d&&a[4]-a[2]<=d)cout<<1<<endl;
				else cout<<0<<endl;
			}
			else if(n==5){
				ll cnt=0;
				if(a[4]-a[1]>d&&a[3]-a[1]<=d&&a[4]-a[2]<=d){
					if(a[5]-a[4]<=d&&a[5]-a[3]>d)cnt++;
					cnt++;
				}
				if(a[5]-a[2]>d&&a[4]-a[2]<=d&&a[5]-a[3]<=d){
					if(a[2]-a[1]<=d&&a[3]-a[1]>d)cnt++;
					cnt++;
				}
				cout<<cnt;
			}
			else{
				ll cnt=0;
				for(int i=1;i<=6;i++){
					if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
						cnt++;
						if(i!=6&&a[i+4]-a[i+3]<=d&&a[i+4]-a[i+2]>d)cnt++;
						if(i!=1&&a[i]-a[i-1]<=d&&a[i+1]-a[i-1]>d)cnt++;
					}
				}
				cout<<cnt;
			}
		}
	}
	else{
		while(t--){
			cout<<0<<'\n';
		}
	}
	return 0;
}
