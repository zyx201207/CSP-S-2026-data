#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,m,a[N],b[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) A=0;
	}
	if(A){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			b[i]+=b[i-1];
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){//i->round i
		int len=0,v[N];
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			int t=0;
			for(int k=1;k<=len;k++){
				if(v[k]==a[j]){
					t=k;
					break;
				}
			}
			if(t!=0){
				for(int k=t;k<=len;k++){
					v[k]=0;
				}
				len=t+1;
			}else len++;
			v[len]=a[j];
		}
		for(int j=1;j<=len;j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}