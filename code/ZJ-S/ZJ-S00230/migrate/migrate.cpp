#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
struct nd{
	long long num,mi_val;
};
vector<nd> a[2000010];
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf(" %d",&x[i]);
		}
		nd tmp;
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(x[j]-x[i]<=d){
					tmp.mi_val=x[j]-x[i];
					tmp.num=1;
					a[i].push_back(tmp);
				}
			}
			
		}
		for(int i=1;i<=n;i++){
			long long mi=LONG_LONG_MAX,num=0;
			if(!a[i].empty()){
				for(int j=0;j<a[i].size();j++){
					if(mi==a[i][j].mi_val)num++;
					else if(mi>a[i][j].mi_val){
						mi=a[i][j].mi_val;
						num=1;
					}
				}
				if(num==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
