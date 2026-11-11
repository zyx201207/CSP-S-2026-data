#include<bits/stdc++.h>
using namespace std;
int cnt[500010],a[500010],id[500010],ans[300010],tmp[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		if(a[n]==1){
			cout<<n<<' '<<cnt[2];
		}else{
			cout<<cnt[1]<<' '<<n;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int len=0;
		memset(id,0,sizeof(id));
		memset(tmp,0,sizeof(tmp));
		for(int j=i;j<=n;j++){
			if(id[a[j]]==0){
				len++;
				tmp[len]=a[j];
				id[a[j]]=len;
			}else{
				for(int k=id[a[j]]+1;k<=len;k++){
					id[tmp[k]]=0;
				}
				len=id[a[j]];
			}
		}
		for(int j=1;j<=len;j++){
			ans[tmp[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}