#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
const int N=2000005;
long long c,tt,n,d,a[N],dis[N],dd[N];
vector<long long>cld[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&tt);
	while(tt--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=int(n);i++){
			scanf("%lld",&a[i]);
			if(i!=1){
				dis[i-1]=a[i]-a[i-1];
				dd[i-1]=dd[i-2]+dis[i];
			}
		}
		/*
		for(int i=int(n-1);i>=1;i--){
			int cnt=0;
			cld[i][cnt]=(long long)(i);
			if(i!=(n-1)){
				for(int j=0;j<cld[i+1].size();j++){
					if(dd[i+1]-dd[int(cld[i+1][j])-1]+dis[i]<=d){
						cnt++;
						cld[i][cnt]=cld[i+1][j];
						
					}
				}
			}
			
		}
		/*for(int i=1;i<n;i++){
			for(int j=0;j<cld[i].size();j++){
				cout<<cld[i][j]<<" ";
			}
			cout<<endl;
		}*/
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4

*/
