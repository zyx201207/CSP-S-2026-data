#include<bits/stdc++.h>
using namespace std;
const int N=5020,M=3020;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n,m;
	int a[N],b[M];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int x[M]={0};
		for(int j=i;j<n;j++){
			x[a[j]]++;
			if(x[a[j]]==2){
				x[M]={0};
				x[a[j]]=1;
			}
		}
		for(int j=0;j<m;j++){
			if(x[j]!=0){
				b[j]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i];
	}
	return 0;
}
