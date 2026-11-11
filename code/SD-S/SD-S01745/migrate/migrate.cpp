#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,t,n,d,a[5005],ans,cnt,b[5005],rr;
vector<int> q;
void sss(int u,int i){//cout<<"u="<<u<<", i="<<i<<"\n";
	if(q[i]-u>=3||a[q[i]]-a[u]>=d||i>=q.size()){
		return ;
	}
	if(i==q.size()-2){
		if(a[q[q.size()-1]]-a[u]<=d){
			cnt++;
		}
		return ;
	}
	sss(min(rr,b[u]),i+1);
	if(b[u]-1>u)sss(min(rr,b[u]-1),i+1);
	if(b[u]-2>u)sss(min(rr,b[u]-2),i+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&t);
	while(t--){ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d){
					b[i]=j;
				}else{
					break;
				}
			}//cout<<i<<": "<<b[i]<<"\n";
		}//cout<<"\n";
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;//cout<<"---"<<l<<"~"<<r<<":\n";
				int j=l,ff=0;q.clear();q.push_back(l);
				while(j<r){
					j=b[j];j=min(r,j);
					q.push_back(j);
					if(j==b[j]&&j<r){
						ff=1;break;
					}
				}
				if(ff)continue;
				
				
//				for(int i=0;i<q.size();i++){
//					cout<<q[i]<<" ";
//				}cout<<"\n";
				
				cnt=0;rr=r;
				sss(l,0);
//				cout<<"\ncnt="<<cnt<<"\n\n";
				if(cnt==2){
					ans++;
				}
				
//				getchar();
			}
		}
		
		printf("%lld\n",ans);
	}
	
	
	
	
	
	return 0;
}
