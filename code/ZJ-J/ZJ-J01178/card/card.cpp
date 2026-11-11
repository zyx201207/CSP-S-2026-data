#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],s[200010],cnt,sk[200010];
struct pos{
	int sz,wz;
}d[200010];
int main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!s[a[i]]){
			d[a[i]].sz=i;
			d[a[i]].wz=i;
			cout<<a[i]<<" "<<d[a[i]].sz<<"\n";
		}
		s[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(sk,0,sizeof sk);
		if(s[a[i]]>1){
			int j=i;
			while(j++){
				cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<sk[a[j]]<<" "<<d[a[j]].wz<<" "<<d[a[j]].sz<<"\n";
				if(a[i]==a[j])break;
				if(a[j]!=a[i] && !sk[a[j]]){
					sk[a[j]]=1;
					if(j==d[a[j]].wz)d[a[j]].sz-=i;
				}
			}
			for(int k=i;k<=j;k++){
				s[a[k]]--;
			}
			i=j-1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i].sz<<" ";
	}
	return 0;
}