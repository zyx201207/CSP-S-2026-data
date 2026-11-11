#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],k[500005];
bool t[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int y=i;
		for(int j=i;j<=n;j++){
			for(int p=i;p<y;p++){
				if(k[p]==a[j]){
					y=p;
					break;
				}
			}
			k[y]=a[j];
			y++;
		}
		for(int j=i;j<y;j++){
			t[k[j]]++;
			//cout<<k[j]<<' ';
		}
		//cout<<endl;
		for(int j=1;j<=m;j++){
			ans[j]+=t[j];
			t[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
