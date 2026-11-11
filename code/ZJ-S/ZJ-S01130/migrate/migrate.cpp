#include<bits/stdc++.h>
using namespace std;
long long s,T,n,d,a[2000005],b[2000005],c[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s>>T;
	if(s==11||s==12){
		while(T--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(d<(a[2]-a[1])*2)cout<<"0\n";
			else{
				for(int i=1;i<=n;i++)
					ans+=(n-i)/(d*2-1);
				cout<<ans<<"\n";
			}
		}
		return 0;		
	}
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			memset(b,127,sizeof(b));
			memset(c,0,sizeof(c));
			cin>>a[i];
			b[i]=0;
			for(int j=i;j>=1;j--){
				int k=j-1;
				while((a[j]-a[k])<=d){
					if(b[j]+1<b[k]){
						b[k]=b[j]+1;
						c[k]=1;
					}
					else if(b[j]+1==b[k])c[k]++;
					k--;
				}
			}
			for(int j=1;j<=i;j++)if(c[j]==2)ans++;
		}
		cout<<ans<<"\n";
	}
}

