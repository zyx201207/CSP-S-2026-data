#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,ans,a[2000006],q[2000006],p[2000006],dq[2000006][4];
bool b[2000006];

int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[i]=a[i]-a[i-1];
			if(p[i]<=d){
				b[i]=1;
			}
		}
		int t=1,h=1;
		dq[t++][1]=a[1];
		dq[t][2]=0;
		dq[t][3]=0;
		while(h<t){
			int sum=p[h+1],i=1;
			while(sum<=d&&h+1+i<=n){
				dq[t++][1]=dq[h][1]+sum;
				dq[t][2]=dq[h]+1;
				dq[t][3]=h;
				sum+=p[p[h+1+i]];
				i++;
			}
		}
		for(int i=1;i<t;i++){
			for(int j=1;j<i;j++){
				if(dq[i][2]==dq[j][2]&&dq[i][1]==dq[j][1])
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}