#include<bits/stdc++.h>
using namespace std;
int w[500005],cnt[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<int> s[m],a[m],t[m];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]].push_back(i);
			cnt[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,sum=0;
		cin>>x>>y;
		sum+=w[x]+w[y];
		int p=0;
		for(int i=0;i<cnt[x];i++){
			int now=x;
			int cur=sum;
			while(now!=y){
			    int sub=s[x][i];
				now=a[sub][i];			
				if(sub==s[y][i]){
				   	break;
				}else{
				   	cur+=w[now];
				   	cur+=t[i][now];
				}
			}
			sum=min(cur,sum);
		}
		cout<<sum<<endl;
	}
	return 0;
}
