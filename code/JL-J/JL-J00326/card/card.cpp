#include <bits/stdc++.h>
using namespace std;
int n,m,k,q,o,ans,cnt;
int a[500005],c[500005],d[500005];
bool b[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) q++;
		if(a[i]==2) o++;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				b[i]=0;
			}
			for(int i=j;i<=n;i++){
				if(a[i-1]!=a[i]&&a[i+1]!=a[i]&&b[a[i-1]]!=1){
					b[a[i-1]]=1;
					b[a[i]]=1;
					q--,o--;
				}else if(a[i]==a[i-1]){
					b[a[i-1]]=1;
					if(a[i]==1) q--;
					else o--;
				}
			}
			ans+=q,cnt+=o;
		}
	}
	cout<<ans<<" "<<cnt;
	/*for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(int l=1;j<=k;l++){
					c[l]=0;
					b[l]=0;
				}
				k=1;
				c[k]=a[j];
			}else{
				b[a[j]]=1;
				k++;
				c[k]=a[j];
			}
		}
		for(int j=1;j<=k;j++){
			d[c[j]]++;
			cout<<c[j]<<" ";
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}*/
	return 0;
}
