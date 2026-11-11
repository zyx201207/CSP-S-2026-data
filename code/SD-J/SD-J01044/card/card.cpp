#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,a[200005],b[200005],c[100005];
	cin >> n >> m;
	for(int i=0;i<200005;i++){
		a[i]=0;
		b[i]=0;
	}
	for(int i=0;i<100005;i++){
		c[i]=0;
	}
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		int x=0;
		for(int j=i;j<n;j++){
			int y=-1;
			for(int k=x;k>=0;k--){
				if(b[k]==a[j]){
					y=k;
				}
			}
			if(y>-1){
				for(int k=y;k<=x;k++){
					b[k]=0;
				}
				x=y;	
			}
			b[x]=a[j];
			x++;
		}
		for(int j=0;j<x;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << c[i] << " ";
	}
	//fclose(stdin);
	//fclose(stdout); 
	return 0;
}
