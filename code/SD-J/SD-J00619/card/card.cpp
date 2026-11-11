#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],put[N],sum[N],cnt,jy[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			put[j]=0,jy[j]=0,b[a[j]]=0;
		}
		for(int j=i;j<n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				for(int k=jy[a[j]];k<cnt;k++){
					put[k]=0;
				}
				cnt=jy[a[j]];
				b[a[j]]=1;
			}
			put[cnt]=a[j];
			jy[a[j]]=cnt;
			cnt++;
		}
		for(int j=0;j<cnt;j++){
			sum[put[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
