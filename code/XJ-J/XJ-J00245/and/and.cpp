#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],maxc=-1100,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=1;i<=n-m+1;i++){
		for(int j=i;j<=m;j++){
			b=a[j];
			for(int k=j+1;k<=n;k++){
				for(int f=k;f<=n;f++){
					b=b&a[f];
					if(f-j+s+1>=m){
						break;
					}
				}
				s++;
				if(b>maxc){
					maxc=b;
				}
			}
			s=0;
		}
	}
	cout<<maxc;
	return 0;
}
