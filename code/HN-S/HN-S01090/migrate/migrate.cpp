#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int qwe,t;
long long isl[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>qwe>>t;
	if(qwe<=6){
		while(t--){
			int n,ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>isl[i];
			}
			for(long long i=1;i<=n;i++){
				for(long long j=i+3;j<=n;j++){
					int sum=0;
					for(long long k=i+1;k<j;k++){
						if(isl[i]+d>=isl[k]&&isl[k]+d>=isl[j]&&isl[i]+d<isl[j])sum++;
					}
					if(sum==2)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else{
		cout<<0;
	}
	return 0;
}

