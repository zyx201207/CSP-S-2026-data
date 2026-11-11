#include<bits/stdc++.h>
using namespace std;
#define PID "card"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
const int N=2e5+10;
int n,m,a[N],pid[N],b[N],l,ans[N];
int main(){
	FI;FO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=0;
		memset(pid,0,sizeof(pid));
		for(int j=i;j<=n;j++){
			if(pid[a[j]]!=0){
				for(int k=pid[a[j]]+1;k<=l;k++){
					pid[b[k]]=0;
				}
				l=pid[a[j]];
			}else{
				pid[a[j]]=++l;
				b[l]=a[j];
			}
		}
		for(int j=1;j<=l;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
