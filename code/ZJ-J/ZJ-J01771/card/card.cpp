#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[3000100],Map[3000100],vec[500100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(Map[a[j]]==0||Map[a[j]]>cnt||vec[Map[a[j]]]!=a[j])
				++cnt,Map[a[j]]=cnt,vec[cnt]=a[j];
			else cnt=Map[a[j]];
		}
		for(int j=1;j<=cnt;j++)ans[vec[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
