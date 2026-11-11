#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int F[N][N];
long long a[N];
int c,n,T;
long long d;
int ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			F[i][i]=0;
			for(int j=i+1;j<=n;j++){
				int l=i,r=j;
				while(l<r){
					int mid=(l+r)/2;
					if(F[i][mid]==-1&&a[j]-a[mid]>d){
						l=r;
						break;
					}
					if(F[i][mid]==-1){
						r=mid;
						continue;
					}
					if(a[j]-a[mid]<=d){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				if(l==j||F[i][l]==-1){
					F[i][j]=-1;
				}
				else{
					F[i][j]=F[i][l]+1;
				}
			}
		}
	/*	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<F[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(F[i][j]==-1)continue;
				int cnt=0;
				for(int k=i+2;k<j;k++){
					if(F[i][k]==-1||F[k][j]==-1){
//						cout<<i<<" "<<j<<" "<<k<<endl;
						continue;
					}
					if(F[i][k]==F[i][k-1]&&F[k][j]==F[k-1][j]&&F[i][k]+F[k][j]==F[i][j]){
						cnt++;
					}
				}
				if(cnt==1){
//					cout<<i<<" "<<j<<endl;
//					cout<<F[i][j]<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<i;j++){
//			cout<<"  ";
//		}
//		for(int j=i;j<=n;j++){
//			cout<<F[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
