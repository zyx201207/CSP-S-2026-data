#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int b[m+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[m+5]={};
		int cnt=i;
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			b[a[j]]++;
			
			if(c[a[j]]>1){
				for(int q=j;q>i;q--){
					if(a[q+1]==a[j]&&q+1!=j) break;
					if(c[a[q]]!=0) b[a[q]]--;
					if(c[a[q]]!=0&&q!=j) c[a[q]]--;
					
					
					
				}
				
			}
			
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

