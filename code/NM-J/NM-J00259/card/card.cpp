#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],v[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=0;
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				v[l++]=a[j];
				b[a[j]]=l;
			}
			else{
				int t=l-b[a[j]];
				for(int k=b[a[j]];k<=l;k++){
					b[a[v[k]]]=0;
					v[k]=0;
				}						
				l=t;
				v[l++]=a[j];
				b[a[j]]=l;
			}
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=bool(b[j]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
