#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
struct s{
	int start,count;
};
s f[2000005];
#define int int
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,t;cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			f[i].start=INT_MAX,f[i].count=0;
		}
		for(int i=1;i<=n;i++)
			cin>>a[i];
		f[1].count=1,f[1].start=0;
		for(int s=1;s<=n;s++)
		{
			for(int i=1;i<=n;i++)
			    f[i].start=INT_MAX,f[i].count=0;
			for(int i=s;i<=n;i++)
				for(int j=i;j>=1&&a[i]-a[j]<=d;j--)
				    if(f[i].start>f[j].start+1){
				    	f[i].count=f[j].count;
				        f[i].start=f[j].start+1;
					}     
				    else if(f[i].start==f[j].start+1)
					    f[i].count+=f[j].count;    
		    for(int i=s;i<=n;i++)
		    	if(f[i].count==2)
		    		ans+=1;	
		} 
		cout<<ans<<endl;
	}
	return 0;
}
