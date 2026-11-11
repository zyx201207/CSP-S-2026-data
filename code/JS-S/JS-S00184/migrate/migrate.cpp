#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,minstep,num,ans;
int a[50005];
pair<int,int> q[5000001];
int T(int x,int y){
	if(a[y]-a[x]<=d) return 1;
	for(int i=y-1;i>=x+1;i--){
		if(a[i]-a[x]<=d){
			return T(i,y)+1;
		}
	}
	return 0;
}
bool turn(int x,int y){
	num=0;
	int head=0;
	int tail=0;
	q[head]=make_pair(x,0);
	head++;
	while(head>tail){
		pair<int,int> xx=q[tail];
		tail++;
		if(xx.first==y&&xx.second==minstep){
			num++;
			if(num>2) return 0;
			continue;
		}
		for(int i=xx.first+1;i<=y;i++){
			if(a[i]-a[xx.first]<=d&&xx.second<minstep){
				q[head]=make_pair(i,xx.second+1);
				head++;
			}
			else break;
		}
	}
	if(num==2) return 1;
	return 0;
}
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				num=0;
				minstep=T(x,y);
				//cout<<x<<' '<<y<<' '<<minstep<<endl;
				//cout<<minstep<<endl;
				if(turn(x,y)){
					//cout<<x<<' '<<y<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
