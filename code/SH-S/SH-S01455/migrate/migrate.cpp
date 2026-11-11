#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,d,minsum,ans,num,ex,n;
const int MAXN=2e6+5;
int a[MAXN];
void dfs(int pos,int sum){
	if(pos==ex){
		if(minsum>sum){
			num=1;
			minsum=sum;
		}else if(minsum==sum){
		//	cout<<sum<<endl;
			num++;
		}
		return ;
	}
	for(int i=pos+1;i<=ex;i++){
		if(a[i]<=d+a[pos])
		    dfs(i,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			int p=a[2]-a[1];
			if(d<p){
				cout<<"0"<<endl;
			}else{
				int k=d/p;
				//if(d%p==0) k++;
				if(d==p) cout<<0<<endl;
				else{
					cout<<max(n-k-2,0ll)<<endl;
				}
			}
			cout<<d<<" "<<p<<" "<<n<<endl;
		}else{
			for(int i=1;i<=n;i++){
				for(ex=i+1;ex<=n;ex++){
					num=0;
					minsum=1e9;
					dfs(i,0);
					if(num==2){
						ans++;
					} 
				}
			}
			cout<<ans<<endl;			
		}
	}
}

