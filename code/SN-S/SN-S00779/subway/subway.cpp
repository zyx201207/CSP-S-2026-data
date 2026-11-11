#include<bits/stdc++.h>
using namespace std;
struct subway{
	int a,t;
};
subway sub[500005][500005];
struct tt{
	int d1,t1;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q,w[500005],k,a1,t1,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i>n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a1>>t1;
			sub[i][j]={a1,t1};
		}
	}
	while(q--){
		queue<tt>s;
		int ans=INT_MAX;
		cin>>x>>y;
		s.push({x,w[x]});
		while(!s.empty()){
			tt b=s.front();
			s.pop();
			if(b.d1==0)continue;
			for(int i=0;i<d;i++){
				tt c=b;
				c.d1=sub[b.d1][i].a;
				c.t1+=sub[b.d1][i].t;
				if(c.d1==y)ans=min(ans,c.t1);
				s.push(c);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
