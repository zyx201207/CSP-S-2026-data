#include<bits/stdc++.h>
using namespace std;
int n,a[500001],m,l,st[500001],cnt,vis[300001],pos[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l=i;cnt=0;
		for(int j=1;j<=m;j++)pos[j]=0;
		for(int j=i;j<=n;j++){
			if(!pos[a[j]]){
				st[++cnt]=a[j];
				vis[a[j]]++;
				pos[a[j]]=cnt;
			}else{
				int tmp=pos[a[j]];
				for(int k=tmp;k<=cnt;k++){
					vis[a[k]]--;
					pos[a[k]]=0;
				}
				cnt=tmp+1;
				st[cnt]=a[j];
				pos[a[j]]=cnt;
				vis[a[j]]++;
			}
		}
	//	for(int j=1;j<=cnt;j++)cout<<st[j]<<' ';
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<vis[i]<<' ';
	return 0;
}