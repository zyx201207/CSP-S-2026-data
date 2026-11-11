#include<bits/stdc++.h>
using namespace std;
int p[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[m],h[m]={0};
	for(int i=0;i<m;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		int b[m],step=0;
		for(int j=0;j<n;j++){
			b[i]=a[i];
		}while(b[m-1]!=0){
			p[step]=b[step];b[step]=0;
			for(int i1=0;i1<step;i1++){
				for(int j1=i1+1;j1<step;i1++){
					if(p[i1]==p[j1]){
						for(int l=i1;l<j1;l++){
							p[l]=0;
						}
					}
				}
			}step++;
		}for(int q=0;q<m;q++){
			if(p[q]!=0){
				h[p[q]]++;
			}
		}
	}for(int i=0;i<m;i++){
		cout<<h[i]<<" ";
	}return 0;
}
