#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
ll n,m,a[N],flag[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,-1,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(flag[a[j]]!=-1){
				for(int i=1;i<=m;i++){
					if(flag[i]>=flag[a[j]]&&a[j]!=i) flag[i]=-1;
				} 
			}else{
				flag[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++){
			if(flag[i]!=-1){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

