#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int a[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			int j=0;
			for(j=i-1;j>=1;j--){
				if(a[j]==a[i]) break;
			}
			if(j==0){
				for(int o=1;o<=i;o++){
					cnt[a[o]]++;
				}
			}
			else{
				for(int k=j;k<=i;k++){
					a[k]=0;
				}
				for(int o=1;o<=i;o++){
					cnt[a[o]]++;
				}
			}
		}
	}
	
	for(int i=1;i<=n*n*n;i++){
		if(cnt[a[i]]!=0&&a[i]!=0)
			cout<<cnt[a[i]]<<" ";
	}
	return 0;
} 
