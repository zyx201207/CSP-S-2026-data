#include <iostream>
#include <cstring>
using namespace std;
const long long N=2e5+7;
long long n;
long long m;
long long a;
long long f[N][35];
long long er[35];
bool p[N];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	er[1]=1;
	for(long long i=2;i<=32;i++){
		er[i]=er[i-1]*2;
	}
	for(long long i=1;i<=n;i++){
		cin>>a;
		p[i]=false;
		for(long long j=32;j>=1;j--){
			if(er[j]<=a){
				f[i][j]=1;
				a-=er[j];
			}
		}
	}
	for(long long i=32;i>=1;i--){
		long long tmp=0;
		for(long long j=1;j<=n;j++){
			if(p[j]){
				continue;
			}
			if(f[j][i]==1){
				tmp+=1;
			}
		}
		if(tmp>=m){
			ans+=er[i];
			for(long long j=1;j<=n;j++){
				if(p[j]){
					continue;
				}
				if(f[j][i]==0){
					p[j]=true;
				}
			}
		}
	}
	cout<<ans;
}
