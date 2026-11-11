#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+5;
int a[N];
int p[N];
int cnt[N];
int find(int x,int n){
	for(int i=1;i<=n;i++){
		if(p[i]==x)return i;
	}
	return -1;
}
int idx=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("caed.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			p[idx++]=a[i];
			int f=find(a[j],n);
			if(f>0){
				for(int k=f;k<=j;k++)p[i]=0;
			idx=f;
			p[idx]=f;
			}
		}
		cnt[p[idx-1]]++;
		memset(p,0,sizeof(p));
		idx=0;
	}	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
