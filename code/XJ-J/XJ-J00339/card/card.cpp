#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],c[300005],T[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			b[i]=a[i];
			if(t[b[i]]==1){
				for(int j=c[b[i]];j<=i;j++){
					b[j]=0;
				}
			}
			else{
				t[b[i]]++;
			}
			c[b[i]]=i;
		}
		for(int i=1;i<=n;i++){
			T[b[i]]++;
			t[b[i]]=0;
			c[b[i]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<T[i]<<" ";
	}
}