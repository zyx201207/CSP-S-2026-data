//胡嘉骏 SN-J00755 陕西省西安爱知中学
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int r[200010];
int main(){
	//freopen("card3.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[1]=a[1]; 
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			r[j]==a[j];
			for(int z=i;z<j;z++){
				r[z]+=a[z];
				if(a[z]==a[j]){
					for(int t=z+1;t<j;t++){
						r[t]=0;
					}
					break;
				}
			}
			b[r[j]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i+1]<<' ';
	}
	return 0;
}
