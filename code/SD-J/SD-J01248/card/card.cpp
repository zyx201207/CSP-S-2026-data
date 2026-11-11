#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005];
int b[200005];
int sum[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int c=0;c<n;c++){
		for(int i=c;i<n;i++){
			bool f=false;
			for(int j=0;j<k;j++){
				if(a[i]==b[j]){
					f=true;
					while(k>j+1){
						b[k--]=0;
					}
					b[k]=0;
					k++;
				}
			}
			if(f==false){
				b[k++]=a[i];
			}
		}
		for(int z=0;z<k;z++){
			sum[b[z]]++;
		}
		for(int z=0;z<k;z++){
			b[z]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
