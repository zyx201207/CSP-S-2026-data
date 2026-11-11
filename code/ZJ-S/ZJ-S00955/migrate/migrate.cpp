#include<bits/stdc++.h>
using namespace std;
int T;
long long n,d,c;
long long x[2000010];
long long numl[2000010],numr[2000010];
long long ans;
deque<int> q;
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			while(!q.empty()&&x[q.front()]<x[i]-d){
				numr[q.front()]=q.size()-1;//cout<<q.size()<<"a\n";
				q.pop_front();
			}
			q.push_back(i);
			numl[i]=q.size()-1;
		}
		while(!q.empty()){
			numr[q.front()]=q.size()-1;//cout<<q.size()<<"a\n";
				q.pop_front();
		}
//		for(int i=1;i<=n;i++)cout<<numl[i];
//		cout<<"\n";
//		for(int i=1;i<=n;i++)cout<<numr[i];
		for(int i=1;i<=n-3;i++){
			if(numr[i]>1){
				for(int j=i;j<=n;j++){
					if(numr[i]+numl[j]-(j-i+1)<0)break;
					if(numr[i]+numl[j]-(j-i+1)==0)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}