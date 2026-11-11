#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN = 5e5+20;
int b[MAXN],ysn[MAXN];
struct node{
	int z,id;
}a[MAXN];
int cnt[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
	}
	for(int i=1;i<=MAXN;i++){
		ysn[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ysn[a[j].z]==0){
				b[j]=a[j].z;
				for(int k=j;k<=n;k++){
					if(a[k].z==a[j].z) a[k].id=j;
					else continue;
				}
				ysn[a[j].z-1]=1;	
			}else{
				for(int k=a[j].id;k<j;k++){
					b[k]=0;
				}
				ysn[a[j].z]=0;
				b[j]=a[j].z;
			}
		}
		for(int j=i;j<=n;j++){
			cnt[b[j]]++;
		}
		for(int j=1;j<=n;j++){
			b[j]=0;
			a[j].id=0;
			ysn[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
