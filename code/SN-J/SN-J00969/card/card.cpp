#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],x=1,t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		x=0;
		for(int i=q;i<=n;i++){
			x++;
			b[x]=a[i];
			for(int j=x;j>=1;j--){
				if(a[i]==b[j]&&i!=j){
					for(int k=j;k<=x;k++){
						b[k]=0;
					}
					b[j]=a[i];
					x=j;
					break;
				}
			}
		}
		for(int i=1;i<=x;i++){
			t[b[i]]++;
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}

