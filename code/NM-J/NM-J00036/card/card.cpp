#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],id[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		int end=0;
		for(int i=0;i<=m;i++)
		id[i]=0;
		for(int j=i;j<=n;j++){
			if(id[a[j]]!=0){
				end=a[j];
			}
			id[a[j]]=j;
		}
		for(int j=end+1;j<=n;j++)
		cnt[a[j]]++;
	}
	for(int i=1;i<=m;i++)
	cout<<cnt[i]<<' ';
	return 0;
}
