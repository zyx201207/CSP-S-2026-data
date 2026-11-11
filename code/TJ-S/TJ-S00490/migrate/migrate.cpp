#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,l;
long long a[2000005];
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("mignate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>l;
		if(l==1 || n<4){
			cout<<0<<endl;
			continue;
		}
		else{
			for(int i=4;i<=n;i++){
				for(int j=1;j<i;j++){
					int land=0;
					if(a[i]-a[j]<=l){
						break;
					}
					else{
						for(int x=j+1;x<i;x++){
							if(a[x]-a[x-1]>l){
								break;
							}
							if(a[x]-a[j]>l && a[i]-a[x]<=l)
								land++;
						}
					}
					if(land==2)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return  0;
}
