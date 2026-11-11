#include<bits/stdc++.h>
using namespace std;
int n,m;
int  a[1000004],b[1000004];
int cnt[1000004];

void kk(int j,int h){
	for(int i=j;i<h;i++){
		b[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		int sumb=n-i;
		int y=0;
		for(int j=i;j<n;j++){
			b[y++]=a[j];
		}
		for(int j=0;j<sumb;j++){
			if(b[j]!=0){
				for(int h=sumb-1;h>j;h--){
					if(b[j]==b[h]){
						kk(j,h);
					}
				}
			}
		}
		for(int j=0;j<sumb;j++){
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}