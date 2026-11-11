#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005]={0},c[500005]={0};
int main(){
	/*freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);*/
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				for(int k=1;k<=m;k++){
					if(b[k]>0){
						b[k]--;
					}
				}
			}
		}for(int z=1;z<=m;z++){
			if(b[z]!=0){
				c[z]+=b[z];
				b[z]=0;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}//3 1 2 1 3 2 3 1 2 1
