#include<bits/stdc++.h>
using namespace std;
int n,m;
int same(int a[],int x,int size){
	for(int i=1;i<=size;i++){
		if(x==a[i]){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+1];
	int sum[m+1];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int put[n+1],size=1;
		for(int j=i;j<=n;j++){
			int r=same(put,a[j],size);
			
			if(r==-1){
				put[size]=a[j];
				size++;
			}
			else{
				size=r+1;
			}
		}
		for(int j=1;j<=size-1;j++){
			sum[put[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
