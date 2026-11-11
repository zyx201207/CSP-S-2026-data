#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T;
int n,dp[2000010],x[2000010],d;
deque<pair<int,int> >q;
int calc(int qwq,int awa){
	return abs(x[qwq]-x[awa]);
}
void Clear(){
	
}
void solve(){
	Clear();
	long long ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int flag=1,qwq=x[2]-x[1];
	for(int i=2;i<=n;i++){
		if(x[i]-qwq!=x[i-1])
			flag=0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			while(!q.empty())
				q.pop_front();
			q.push_back({i,1});
			for(int j=1;j<=n;j++)
				dp[j]=100000000;
				
			for(int j=i+1;j<=n;j++){
				while(!q.empty()&&calc(q.front().first,j)>d)
					q.pop_front();
				if(q.empty())
					break;
				if(q.size()==1){
					dp[j]=dp[q.front().first]+1;
					if(q.front().second==2)
						ans++;
					q.push_back({j,q.front().second});
				}
				else if(q.size()==2){
					pair<int,int>tmp=q.front();
					dp[j]=dp[q.front().first]+1;
					q.pop_front();
					if(dp[tmp.first]==dp[q.front().first])
						q.push_back({j,tmp.second+q.front().second});
					else
						q.push_back({j,tmp.second});
					q.push_front(tmp);
					if(q.back().second==2)
						ans++;
				}
				else{
					pair<int,int>tmp1=q.front();
					q.pop_front();
					pair<int,int>tmp2=q.front();
					q.pop_front();
					dp[j]=dp[tmp1.first]+1;
					if(dp[tmp1.first]!=dp[tmp2.first])
						q.push_back({j,tmp1.second});
	
					else if(dp[tmp1.first]==dp[tmp2.first]&&dp[tmp2.first]!=dp[q.front().first])
						q.push_back({j,min(3ll,tmp1.second+tmp2.second)});
					else
						q.push_back({j,3});
					q.push_front(tmp2);
					q.push_front(tmp1);
					if(q.back().second==2)
						ans++;
				}
	//			cout<<q.size()<<" "<<q.back().first<<" "<<q.back().second<<"\n";
			}
	//		cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
		return ;
	}
	if(flag){
		for(int i=1;i<=n;i++)
			if(x[i]-x[1]>d){
				flag=i-1;
				break;
			}
		if(flag==1||flag==2)
			cout<<"0\n";
		else
			cout<<n-flag*2+3<<"\n";
		return ;
	}
	int l=0,r=n+1;
	for(int i=1;i<=n;i++){
		if(calc(1,i)<=d&&calc(i,n)<=d){
			if(!l)
				r=l=i;
			else
				r=i;
		}
	} 
	if(l){
		if(r-l+1>=3||l==1)
			cout<<"0\n";
		else if(r-l+1==2){
			int pos=r+1,tmp=l-1;
			for(int i=l;i<=n;i++)
				if(calc(i,l-1)<=d)
					tmp=i;
			for(int i=1;i<l-1;i++)
				ans+=(n-tmp);
			if(tmp==r)
				ans+=n-tmp;
		}
		else{
			int pos=r+1,tmp=l-1,awa=0;
			for(int i=l;i<=n;i++)
				if(calc(i,l-1)<=d)
					tmp=i;
			if(l-2>0){
				for(int i=1;i<=n;i++)
					if(calc(i,l-2)<=d)
						awa=i;
				for(int i=1;i<=l-2;i++)
					ans+=tmp-awa;
				if(tmp!=l)
					ans+=n-tmp; 
			}
			else
				ans=0;
		}
		cout<<ans<<"\n";
		return ;
	}
	cout<<"0\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)	
		solve();
	
	return 0;
} 
