#include<bits/stdc++.h>
using namespace std;
int n,m,i1,a[500050];
bool t[1000000];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(i1<n-1){
		for(int i=i1;i<n;i++){
			int z=i;
			for(int j=a[i+1];j<n;j++){
				if(a[j]==a[z]){
					i=j;
					break;
				}
			}
			t[a[z]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
	return 0;
}
