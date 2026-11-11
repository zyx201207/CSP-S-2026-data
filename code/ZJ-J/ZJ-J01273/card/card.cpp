#include<bits/stdc++.h>
using namespace std;
int n,m;
long long cnt[500005];
int a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=-1;
		}
		for(int j=i;j<=n;j++){
			for(int l=i;l<j;l++){
			    if(b[l]==a[j]){
			    	for(int k=i;k<=l;k++){
			    		b[k]=-1;
					}
					b[l]=a[j];
				}
			}
			
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=-1){
				cnt[b[j]]++;
			}
			
        }
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	fclose(stdin);
	return 0;
}
