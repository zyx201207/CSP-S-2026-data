#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int k=1;k<=n;k++){
	int j=1;
	for (int i=k;i<=n;i++){
		b[j]=a[i];
		for (int q=1;q<=j;q++){
			if (b[j]==b[q]){
				for (int w=q+1;w<=j;w++){
					b[w]=0;
				}
				break;
			}
		}
		j++;
	}
	for (int r=1;r<=j;r++){
		if (b[r]!=0){
			c[b[r]]++;
			//cout<<c[r]<<"\n";
			b[r]=0;
		}
	}
}
	for (int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

