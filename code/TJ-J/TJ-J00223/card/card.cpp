#include<bits/stdc++.h>
using namespace std;
long long a[200020],n,m,maxn=-1,b[200020],cnt[200020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=-1;
	}
	for(int l=1;l<=n;l++){
    for(int k=1;k<=n;k++){
    	b[k]=a[k];
    	bool f=1;
    	for(int j=k-1;j>=1;j--){
    		if(b[j]==b[k]){
    			f=0;
    			//sum--;
    			break;
			}
		}
		if(f==0){
			for(int j=k-1;j>=1;j--){
    		    b[j]=-1;
		}
		}
	}
	for(int i=1;i<=n;i++){
		cnt[b[i]]++;
	}
}
    for(int i=1;i<=m;i++){
    	cout<<cnt[i]<<" ";
	} 
	return 0;
} 
