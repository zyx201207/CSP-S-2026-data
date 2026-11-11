#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[300005],d[500005];
bool c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[j]=a[j];
			if(c[b[j]-1]==0){
				b[j]=a[j];
				c[b[j]-1]=1;
			}else{
				for(int k=j;k<n;k++){
					b[k]==0;
				}
				b[j]=a[j];
			}
		}
		for(int j=i;j<n;j++){
			d[b[j]-1]+=1;
		} 
	}
	for(int i=0;i<m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}

