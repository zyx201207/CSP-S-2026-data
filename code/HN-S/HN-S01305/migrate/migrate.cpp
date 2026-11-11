#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005],t[305][305],q[305][305];
int main(){
	freopen("migrate4.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,p;
	cin>>c>>p;
	if(c==11 || c==12){
		while(p--){
			ll n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
//				scanf("%d",&x[i]);
			}
			ll t=x[2]-x[1],k=3;
			if(2*t>d){
				cout<<"0\n";
			}
			else{
				while(1){
					if(k*t>d){
						break;
					}
					k++;
				}
				if(k==4){
					k++;
				}
//				cout<<n<<" "<<k<<" "<<t<<" "<<d<<"\n";
				cout<<max((ll)0,n-k)<<"\n";
			}
		}
		return 0;
	} 
	while(p--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				t[i][j]=0;
				q[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					t[i][j]=t[j][i]=1;
				}
				else{
					t[i][j]=t[j][i]=1005;
				}
			}
			t[i][i]=1005;
		}
//		cout<<"\n\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<t[i][j]<<" "; 
//			}cout<<"\n";
//		} 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(k==j || k==i){
						continue;
					}
					if(t[i][k]+t[k][j]<t[i][j]){
						t[i][j]=t[i][k]+t[k][j];
						q[i][j]=max(1ll,q[i][k])*max(1ll,q[k][j]);
//						cout<<i<<" "<<j<<" "<<k<<" 1/"<<"\n";
					}
					else if(t[i][k]+t[k][j]==t[i][j]){
						q[i][j]+=max(1ll,q[i][k])*max(1ll,q[k][j]);
//						cout<<i<<" "<<j<<" "<<k<<" "<<q[i][j]<<"\n";
					}
				}
			}
		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<t[i][j]<<" "; 
//			}cout<<"\n";
//		} 
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<q[i][j]<<" "; 
//			}cout<<"\n";
//		} 
		int ans=0;
//		cout<<q[1][4]<<" ";
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(q[i][j]>=2){
//					cout<<i<<" "<<j<<" "<<q[i][j]<<"\n";	
				}
				if(q[i][j]==2){
					ans++;
//					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
} 
