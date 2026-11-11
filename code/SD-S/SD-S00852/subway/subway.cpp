#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int N=500,M=500000,D=20;
 
struct st{
	int b;
	lint c;
};
struct an{
	int a,b,i;
	lint c;
}ans[100005];
int c,n,m,d,q;
lint A[M],dis[600005];
vector<st>a[600005]; 
bool operator < (const st&a,const st &b){
	return a.c>b.c;
} 
bool p(an a,an b){
	if(a.a==b.a){
		return a.b<b.b;
	}
	return a.a<b.a;
}
bool p1(an a,an b){ 
	return a.i<b.i;
}
void di(int be){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<st>q;
	q.push({be,A[be]});
	dis[be]=0;
	while(q.size()){
		st l=q.top();
		q.pop();
		for(auto i:a[l.b]){
			if(i.c+l.c<dis[i.b]){
				q.push({i.b,i.c+l.c});
				dis[i.b]=i.c+l.c;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	 
	for(int i=1;i<=m;i++){
		cin>>A[i];
//		A[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>>ai>>ti;
			a[i+M+10].push_back({ai,ti});
			a[ai].push_back({i+M+10,ti}); 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ans[i].a>>ans[i].b;
		ans[i].i=i;
	}
	sort(ans+1,ans+1+q,p);
	for(int i=1;i<=q;i++){
		di(ans[i].a);
		for(int j=i;;j++){
			if(ans[i].a==ans[j].a){
				ans[j].c=dis[ans[j].b]+A[ans[j].b];
			}else{
				i=j-1;
				break;
			}
		}
	}
	sort(ans+1,ans+1+q,p1);
	for(int i=1;i<=q;i++){
		cout<<ans[i].c<<"\n";
	}
	return 0;
}

