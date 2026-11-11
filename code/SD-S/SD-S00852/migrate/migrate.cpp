#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint n,c,t,d,a[2000005],f[2000005];
struct st{
	lint a,b; 
}; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int z=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){ 
			memset(f,0,sizeof(f));
			queue<st>q,q1;
			q.push({i,0});
			f[i]=1;
			for(int j=i+1;j<=n;j++){ 
				while(q.size()&&a[j]-a[q.front().a]>d){ 
					q.pop();
				}
//				cout<<q.size()<<"'";
//				cout<<"'";
//				while(a[j]-a[l]>d){
//					l++;
//				}
				if(!q.size())continue;
				q1=q;
				st li=q.front();
				q.pop();
				f[j]+=f[li.a];
				
//				cout<<"\"";
				for(;q.size();){
					st fr=q.front();
					q.pop();
					if(fr.b==q1.front().b){ 
						f[j]+=f[li.a];
					}else break;
				}
//				cout<<"'";
				if(f[j]==2)z++;
				q=q1;
				while(q.size()&&q.back().b>li.b+1)q.pop();
				q.push({j,li.b+1});
//				cout<<"\"|";
			}
//			for(int i=1;i<=n;i++){
//				cout<<f[i]<<' ';
//			}
//			cout<<"\n";
		}
		cout<<z<<'\n';
	}
	return 0;
}

