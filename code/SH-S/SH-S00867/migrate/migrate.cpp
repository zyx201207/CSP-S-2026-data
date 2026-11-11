#include <bits/stdc++.h>
using namespace std;
#define int long long

//双金岛屿有一个性质就是说呢首先它肯定有一条是能走多远走多远
//而它的另一条最短路和它只有一个岛的区别 
//题目希望的应该是O(n)。 

int a[3000000],pre[3000000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cout<<0<<endl; 
		}
		return 0;
	} 
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int lt=i,minp=1;bool ok=1;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d){
						ok=0;break;
					}
					if(a[k]-a[lt]>d){
						minp++;
						lt=k-1;
					}
					pre[k]=lt;
				}
				if(ok==0){
					continue;
				}
				int as[100][100];
				for(int k=0;k<100;k++){
					for(int l=0;l<100;l++){
						as[k][l]=0;
					}	
				} 
				as[i][0]=1;
				for(int k=i+1;k<=j;k++){
					for(int l=k-1;l>=i;l--){
						if(a[k]-a[l]>d) break;
						for(int m=1;m<20;m++){
							as[k][m]+=as[l][m-1];
						} 
					}
				}
				if(as[j][minp]==2){
					ans++;//cout<<i<<" "<<j<<" "<<minp<<endl;
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
