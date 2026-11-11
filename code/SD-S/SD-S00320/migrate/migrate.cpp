#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
int ans,c,t,n,d,a[2000010],num[2000010],iswit[2000010];
int bfs(int st){
//	cout<<"in st:"<<st<<'\n';
	queue<int>que,wit;
	que.push(st);
	for(int i=st;i<=n;i++)num[i]=iswit[i]=0;
	num[st]=1;iswit[st]=2;
	while(!que.empty()){
		int sz=que.size();
		while(sz--){
			int t=que.front();
			que.pop();
			for(int i=t+1;i<=n&&a[i]-a[t]<=d;i++){
				if(iswit[i]==2)continue;
				if(iswit[i]==1){
					num[i]++;
//					cout<<"t="<<t<<" i:"<<i<<" num["<<i<<"]++\n";
				}else{
					wit.push(i);
					num[i]=1;
					iswit[i]=1;
//					cout<<"t="<<t<<" i:"<<i<<" num["<<i<<"]=1\n";
				}
			}
		}
		while(!wit.empty()){
			que.push(wit.front());
			iswit[wit.front()]=2;
			wit.pop();
		}
	}
	int k=0;
	for(int i=st;i<=n;i++){
		if(num[i]==2)k++;
	}
	return k;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
