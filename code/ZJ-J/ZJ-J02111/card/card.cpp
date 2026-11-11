#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
int n,m,a[N],q[N],t[N],ans[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int k=1;k<=n;k++){
		memset(q,0,1e6+10);
		memset(t,0,1e6+10);
		q[1]=a[k];
		t[a[k]]++;
		int len=1;
		for(int i=k+1;i<=n;i++){
			if(t[a[i]]==0){
				q[++len]=a[i];
				t[a[i]]++;
			}else{
				bool b=0;
				int p=0;
				for(int j=1;j<=len;j++){
					if(q[j]==a[i]){
						b=1;
						p=j;
					}
					if(b){
						t[q[j]]--;
					}
				}
				len=p;
				q[len]=a[i];
			}	
		}
		for(int i=1;i<=m;i++){
			if(t[i]) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
