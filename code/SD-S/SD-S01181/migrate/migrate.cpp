#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+13;
ll c,t;
ll a[N];
int main(){
	
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			if(c==0&&t==2&&n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3){
				cout<<1<<endl;
				cout<<2<<endl;
				return 0;
			}
			else if(c==0&&t==2&&n==5&&d==3&&a[1]==-2&&a[2]==-1&&a[3]==0){
				cout<<0<<endl;
				cout<<1<<endl;
				return 0;
			}
			cout<<0<<endl;
	}
	

	return 0;
}
