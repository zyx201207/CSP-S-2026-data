#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,x[2000010],sor[2000010][2],l,r,tp,ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		l=0;r=n+1;
		ans=0;
		memset(sor,0,sizeof(sor));
		for(int i=1;i<=n;i++)
			cin>>x[i];
		x[0]=x[1]-1;
		x[n+1]=x[n]+1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[l]>d)l++;
			sor[l][0]++;
		}
		for(int i=n;i>=1;i--){
			while(x[r]-x[i]>d)r--;
			sor[r][1]++;
		}
		for(int i=1;i<n;i++)
		    ans+=min(sor[i][0],sor[i+1][1]);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
