#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],cnt[N],b[N],k,pre[N];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]>a[i])f=1;
	}
	if(!f){
		long long t=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
	}
	else if(m==1){
		cout<<1;
	}
	else if(m==2){
		cout<<"2 2";
	}
	else {
		for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		k=0;
		for(int j=i;j<=n;j++){
			for(int h=1;h<=k;h++){
				if(a[j]==b[h]){
					k=h;
					break;
				}
			}
			k++;
			b[k]=a[j];
		}
		for(int j=1;j<=k;j++){
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}	
	}
	return 0;
}
