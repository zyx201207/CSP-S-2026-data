#include<cstdio>
#include<iostream>
#include<queue>
#define LL long long
using namespace std;
const int N=2e6+100;
int c,t,n,len[N],cnt,ans;
bool f[N];
int q[N],head,tail;
LL d,x[N];
queue<int> qu;
void ff(int i,int j){
	len[j]=len[q[head]]+1;
	f[j]=1; cnt++; ans++;
	qu.push(j);
}
void solve1(){
	ans=0;
	for(int i=1;i<=n-1;i++){
		head=1; tail=0; cnt=0;
		for(int j=1;j<=n;j++) f[j]=0;
		q[++tail]=i; len[i]=0;
		while(!qu.empty()) qu.pop();
		for(int j=i+1;j<=n;j++){
			while(head<=tail&&x[j]-x[q[head]]>d){
				if(f[head])
					cnt--,qu.pop();
				head++;
			}
			if(head>tail) break;
			if(!(cnt&&len[qu.front()]==len[q[head]])){
				if(tail==head+1&&len[q[head]]==len[q[head+1]]) ff(i,j);
				else if(tail>head+1&&len[q[head]]==len[q[head+1]]&&len[q[head+1]]!=len[q[head+2]]) ff(i,j);
				else len[j]=len[q[head]]+1;
			}
			else if(qu.front()==q[head]&&(head==tail||len[q[head]]!=len[q[head+1]])) ff(i,j);
			else len[j]=len[q[head]]+1;
			q[++tail]=j;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		solve1();
	}
	return 0;
}
