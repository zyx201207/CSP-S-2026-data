#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
int a[N][509];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=1;
	for(int cnt=1;cnt<=n;cnt++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int station,dis;
			cin>>station>>dis;
			a[cnt][station]=dis;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		int line=0;
		bool flag=1;
		ans+=(w[x]+w[y]);
		int temp=1e5+10;
		for(int j=1;j<=n;j++){
			if(a[j][y]!=0 && a[j][x]!=0){
				ans+=a[j][x];
				ans+=a[j][y];
				flag=0;
			}
			else if(a[j][y]!=0){
				if(a[j][y]<temp){
					temp=a[j][y];
					line=j;
				}
			}
		}
		if(flag){
			int pos=y;
			ans+=temp;
			temp=1e5+10;
			int cnt=line;
			for(int i=pos-1;i>=1;i--){
				for(int j=1;j<=n;j++){
					if(a[j][i]!=0 && j!=line && a[j][x]!=0){
						if(a[j][i]<temp){
							temp=a[j][i];
							line=j;
							pos=i;
						}
					}
				}
			} 
			ans+=temp;
			ans+=a[cnt][pos];
			ans+=a[line][x];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
