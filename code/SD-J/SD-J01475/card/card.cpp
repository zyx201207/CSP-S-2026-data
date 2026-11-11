#include<bits/stdc++.h>
using namespace std;

const int N=500010,M=300010;
int a[N]={};
int q[N]={};
int w[N]={};
int sum[M]={};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=a[i];
		w[i]=a[i];
	}
	int q=n;
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]&&j!=i){
					for(int z=i;z<j;z++){
						a[z]=m+1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=m+1){
				sum[a[i]]++;
			}
		}
		n-=1;
		for(int i=1;i<=n;i++){
			a[i]=w[i];
			cout<<a[i]<<" ";//
		}cout<<endl;//
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
