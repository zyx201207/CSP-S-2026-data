#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[40],a[200010],del[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=32;k>=0;k--){
			c[k]+=(a[i]>>k&1); 
		}
	}
	int ans=0;
	for(int i=32;i>=0;i--){
//		cerr<<"in "<<i<<" "<<c[i]<<"\n";
		if(c[i]>=m){//选择这一位； 
			ans+=(1<<i);
			//此时有n-c[i]个数没有选，舍弃 
			for(int j=1;j<=n;j++){
				if((a[j]>>i&1)==0&&del[j]==0){//该数不选
					del[j]=1;
					for(int k=i-1;k>=0;k--){
						if(a[j]>>k&1){
//							cerr<<"c"<<k<<"--\n";
							c[k]--;
						}
					}
				}
			} 
		}
	}
//	for(int i=0;i<=32;i++){
//		cerr<<c[i]<<" ";
//	}
	cout<<ans;
	return 0;
}
