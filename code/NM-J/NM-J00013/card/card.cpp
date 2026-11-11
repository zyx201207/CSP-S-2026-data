#include<iostream>
using namespace std;
int main(){
	int n,m,l;
	int a[500005],b[500005],c[300005];
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;j<=j;k++){
				if(a[j]==b[k]){
					for(int k=k+1;k<=j;k++){
						b[k]=0;
					}
				}break;
			}
		}for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				l=1;
				if(b[k]==l){
					c[k]+=1;
				}
			}
		}
	}for(int i=1;i<=m;i++){
		std::cout<<c[i]<<" ";
	}return 0;
}
