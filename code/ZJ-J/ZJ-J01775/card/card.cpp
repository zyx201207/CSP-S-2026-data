#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],t[500005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			bool flag=false;
			for(int k=1;k<=cnt;k++){
				if(d[k]==a[j]){
					flag=true;
					cnt=k;
					break;
				}
			}
			if(!flag){
				++cnt;
				d[cnt]=a[j];
			}
		}
		for(int k=1;k<=cnt;k++){
			t[d[k]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<' ';
	return 0;
}
