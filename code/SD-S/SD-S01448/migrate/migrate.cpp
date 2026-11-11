#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n,d;
int x[N],r[N],l[N],vis1[N],vvis1[N],vis2[N],vvis2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int p=1;
		for(int i=1;i<=n;i++){
			while(x[p+1]-x[i]<=d&&p+1<=n){
				p++;
			}
			r[i]=p;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(x[i]-x[p-1]<=d&&p-1>=1){
				p--;
			}
			l[i]=p;
		}
		for(int i=1;i<=n;i++){
			if(r[i]==r[i-1]){
				vis1[i]=1;
			}
			if(r[i]==r[i-2]){
				vvis1[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(l[i]==l[i+1]){
				vis2[i]=1;
			}
			if(l[i]==l[i+2]){
				vvis2[i]=1;
			}
		}
		int anss=0;
		for(int pl=1;pl<=n;pl++){
			for(int pr=pl+1;pr<=n;pr++){
				int ll=pl,flag=0,cnt=0;
				while(r[ll]<pr&&r[ll]!=ll){
					ll=r[ll];
					if(vvis1[ll]||r[ll-2]>=pr){
						flag=1;
					}
					if(vis1[ll]||r[ll-1]>=pr){
						cnt++;
					}
				}
				if(cnt==1&&flag==0){
					anss++;
				}
			}
		}
		cout<<anss<<'\n';
	}
	return 0;
} 
