#include<bits/stdc++.h>
using namespace std;
int n,m,a[2400086],b[2400086],c[2400086],d[2400086],k=1,f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]<=0){
				b[a[j]]=1;
				c[k]=a[j];
				k++;
			}
			else{
				f=0;
				for(int l=1;l<=n;l++){
					if(c[l]==a[j]){
						k=l;
						f=1;
					}
					if(f==1)b[c[l]]--;
				}
				b[a[j]]++;
				c[k]=a[j];
				k++;				
			}
			//cout<<k<<" ";
			
			//cout<<endl;
		}
		//cout<<endl;
		for(int j=1;j<=n;j++){
			if(j<k)d[c[j]]++;
			b[a[j]]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
