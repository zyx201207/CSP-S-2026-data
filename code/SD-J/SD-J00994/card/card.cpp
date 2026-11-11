#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 3e5+10;
int a[N];
bool b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= m; i++){
		int ans = 0;
		for(int j = 1; j <= n;j++){
			for(int l = 1; l <= m; l++)
				b[l]=false;
			int x=j,y=j;
			b[a[j]]=true;
			while(y<n){
				y++;
				if(b[a[y]]==true){
					int cnt;
					for(int k=x;k<y;k++){
						if(a[k]==a[y])
							cnt = k;
					}
					for(cnt;cnt<y;cnt++){
						b[a[cnt]]=false;
					}
					if(b[a[x]]==false)
						x=y;
					b[a[y]]=true;
				}else{
					b[a[y]]=true;
				}
			}
			if(b[i]==true) ans++;
		}	
		cout<<ans<<' ';
	}
	return 0;
}
