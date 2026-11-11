#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[500010],a[550][500010],t[550][500010],x,y,ans;
long long minv,f[500010],cnt;
void fast(long long x,long long y){
	while(cnt>0){
		ans=0;
		int t1=x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==t1){
					ans+=t[i][j];				
				} 
				if(f[a[i][j]]>1){
					t1=a[i][j];
					ans+=t[i][j];
					f[a[i][j]]--;
					break;
				}
			}
		}
		cnt--;
		minv=min(minv,ans+w[x]+w[y]);
	}
	cout<<minv<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[a[i][j]]++;
		}
	}
	for(int i=1;i<=500000;i++){
		if(f[i]>1) cnt++;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		fast(x,y);
	}
	return 0;
} 
