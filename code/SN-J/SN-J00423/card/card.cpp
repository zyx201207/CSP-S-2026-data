#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[500005],e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int w=0;w<n;w++){
		e=w;
		for(int i=w;i<n;i++){
			num[a[i]]++;
			for(int j=i-1;j>=e;j--){
				if(a[i]==a[j]){
					e=i+1;
					for(int k=j;k<i;k++) --num[a[k]];
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
