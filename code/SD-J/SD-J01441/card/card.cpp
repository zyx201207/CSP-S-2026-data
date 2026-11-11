#include<bits/stdc++.h>
using namespace std;
long long t[100005],a[500005],n,m,b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[j]=a[j];
			bool x=0;
			for(int k=i;k<j;k++){
				if(b[k]==a[j]){
					x=1;
					b[k]=-1;
				}
				if(x==1){
					b[k]=-1;
				}
			}
		}
		for(int k=i;k<n;k++){
			if(b[k]!=-1){
				t[b[k]]++;
			}
			b[k]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
