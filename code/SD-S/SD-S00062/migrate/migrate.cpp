#include <bits/stdc++.h>
using namespace std;
long long c,t,d,n,a[2000006],rzd[2000006],lzd[2000006],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans = 0;
		cin>>n>>d;
		int rjx = 1;
		int zjx = n;
		for(int i=1;i<=n;i++){
		cin>>a[i];
	}memset(lzd,0,sizeof(lzd));
	memset(rzd,0,sizeof(rzd));
		for(int i=1;i<=n;i++){
			while((rjx<=n)&&((a[rjx]-a[i])<=d)){
				rjx++;
			}if(rjx-1!=i)rzd[rjx-1] += rzd[i]+1;
			//cout<<"rjx="<<rjx<<"rzd[i]="<<rzd[i]<<"rzd[rjx-1]="<<rzd[rjx-1];
			while((zjx>=1)&&((a[n-i+1]-a[zjx])<=d)){
				zjx--;
			}if(zjx+1!=n-i+1)lzd[zjx+1] += lzd[n-i+1]+1;
			
		}
		for(int i=2;i<=n-1;i++){
			ans+=rzd[i]*lzd[i-1];
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}



