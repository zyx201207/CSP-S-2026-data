#include<bits/stdc++.h>
using namespace std;


#define ll long long 
const int N=500010;

ll a[N],ans[300010],b[300010];

bool k[300010];



int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int p=1;p<=n+3;p++){
			b[p]=0;
			k[p]=0;
		}
		for(int j=i;j<=n;j++){
			if(k[a[j]]==0){
				b[j]=a[j];
				k[a[j]]=1;	
			}
			else {
				int kk=j-1;
				while(b[kk]!=a[j]){
					k[b[kk]]=0;
					b[kk]=0;
				
					kk--;
				}
				b[kk]=0;
				b[j]=a[j];
			}
		}
		for(int j=1;j<=n;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
