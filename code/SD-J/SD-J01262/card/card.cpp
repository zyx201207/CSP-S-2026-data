#include<bits/stdc++.h> 
using namespace std;
int n,m,ans,top=0;
int st[500001];
int a[500010],f[500001],k[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    st[i]=a[i];
	    f[i]=0;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
		k[i]=0;
		st[i]=0;
		}
		int l=0,r=0;
	for(int i=j;i<=n;i++){
		int x=a[i];
		r++;
		if(k[x]==0) {
			k[x]=i-j+1;
			st[r]=x;
		}
		else if(k[x]>0){
			r=k[x];
			k[x]=k[x];
		}
		}
	for(int i=1;i<=r;i++){
		f[st[i]]++;
	}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
