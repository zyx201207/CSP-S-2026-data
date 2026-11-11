#include<bits/stdc++.h>
using namespace std;int zm[500005],sheng[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	int a[500005],top=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int l=0;l<n;l++){	
		for(int i=l;i<n;i++){
			zm[top]=a[i];
			top++;
			for(int j=0;j<top-1;j++){
				if(zm[j]==a[i]){
					top=j;
					for(int k=j;k<i-1;k++){
						zm[k]=0;	
					}
					zm[top]=a[i];
					top++;
				}
			}
		}
		for(int i=0;i<top;i++){
			if(zm[i]!=0){
				sheng[zm[i]]++;
			}
		}memset(zm,0,sizeof(zm));
	}for(int i=1;i<=m;i++){
		cout<<sheng[i];
		if(i!=n){
			cout<<' ';
		}
	}return 0;
	fclose(stdin);
	fclose(stdout);
}