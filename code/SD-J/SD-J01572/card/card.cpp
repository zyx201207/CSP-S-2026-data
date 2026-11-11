#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool A;
int cnt[300005];
int fir[300005];
int ans[300005];
int str[300005],top;
bool vis[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			A=0;
		}
		cnt[a[i]]++;
		if(fir[a[i]]){
			continue;
		}
		fir[a[i]]=i;
	}
    if(A){
        for(int i=1;i<=m;i++){
        	cout<<n<<' ';
		}
	}else{
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(0));
			top=0;
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					str[++top]=a[j];
					vis[a[j]]=1;
				}else{
					while(str[top]!=a[j]){
						vis[str[top]]=0;
						top--;
					}
				}
			}
			for(int j=1;j<=top;j++){
				ans[str[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
} 
