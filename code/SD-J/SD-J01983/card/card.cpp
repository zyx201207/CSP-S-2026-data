#include<bits/stdc++.h>
using namespace std;
//struct Node{
//	int idh;
//	int idw;
//}t[300001];
int n,m,a[500001],t[500001],p[500001],cnt,ans;
bool ct[500001],flag=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			ct[j]=1;
			p[j]=0;
		}
		cnt=0;
		ans=0;//4 3\n 1 2 1 3
		for(int j=i;j<=n;++j){
			flag=0;
			for(int l=cnt;l>=1;--l){
				if(a[j]==p[l]){
					for(int ll=cnt;ll>=1;--ll){
						ct[ll]=0;
					}
					cnt++;
					p[cnt]=a[j];
					flag=1;
					break;
				}
			}
			if(flag==0){
				cnt++;
				p[cnt]=a[j];
			}
			
		}
		for(int j=1;j<=cnt;++j){
			if(p[j]==i&&ct[j]==1){
				ans++;
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}

