#include<bits/stdc++.h >
#define intl long long
using namespace std;
intl n,m,a[500005],b[500005],t[300005],s,cnt,sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(intl i=1;i<=n;i++){
		cin>>a[i];
	}
	for(intl i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(t,0,sizeof t);
		for(intl j=i;j<=n;j++){
			if(t[a[j]]==0){
				b[++cnt]=a[j];
				t[a[j]]=cnt;
			}else{
				for(int k=t[a[j]]+1;k<=cnt;k++) t[b[k]]=0;
				cnt=t[a[j]];
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]!=0) sum[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
