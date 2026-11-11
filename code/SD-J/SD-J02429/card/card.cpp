#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[300005];
int d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=1,sum=n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=cnt;j<=n;j++){
			if(b[a[j]]==0){
				a[sum+1]=a[j];
				b[a[j]]++;
				sum++;
			}else{
				for(int k=j;k<=n;k++){
					b[a[k]]=0;
					d[a[k]]=0;
					sum-=1;
				}
			}
		}
		for(int j=1;j<=sum;j++){
			c[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
