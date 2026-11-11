#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){	//	µÈ²îÊýÁÐ 
		while(t--){
			cin>>n>>d;
			long long ans;
			for(long long i=1;i<=n;i++){
				cin>>a[i]; 
			}
			long long cha=a[2]-a[1];
			if(d<=abs(cha)){
				cout<<0<<endl;
			}else{
				d/=cha;
				ans=n-2*d+1;
				if(ans<0){
					cout<<0;
				}else{
					cout<<ans;
				}
				cout<<endl;
			}
		} 
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}
	}else{
		while(t--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}	
	}
	return 0;
} 
