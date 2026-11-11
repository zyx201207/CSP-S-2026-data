#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000005],n,d;
map<int,int>ma,mb;
bool check(int l,int r){
	queue<int>q,qq;
	q.push(l),qq.push(1);
	int flag=1;
	while(!q.empty()){
		int cnt=q.front()+1,o=a[q.front()],p=qq.front();
		if(flag!=p){
			flag++;
			for(int i=1;i<=n;i++){
				if(mb[i]==0&&ma[i]>0){
					mb[i]=1;
					if(ma[i]==2&&i==r){
						return 1;
					}
				}
			}
			ma.clear();
		}
		while(a[cnt]-o<=d){
			if(cnt>r){
				break;
			}
			q.push(cnt);
			qq.push(p+1);
			ma[cnt]++;
		}
		q.pop();
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k]-a[j]>d){
					break;
				}
				ans+=check(j,k);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
