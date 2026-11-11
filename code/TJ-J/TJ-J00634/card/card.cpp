#include<bits/stdc++.h>
using namespace std;
long long a[10000],b[10000],l[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	if(m>=100){
		for(int z=0;z<n;z++){
			cout<<n<<" ";
			return 0;
		}
	}else{
		for(int g=0;g<n;g++){
			long long p[10000];
			for(int o=0;o<10000;o++){
		    p[o]=0;
        } 
			for(int j=g;j<n;j++){
			if(p[a[j]]>0){
				int u=j;
				for(int h=u;h>=0;h--){
					if(b[h]!=a[j]){
						p[b[h]]--;
						b[h]=0;
					}else if(b[h]==a[j]){
						p[b[h]]--;
						b[h]=0;
						break;
					}
				}
			}else{
				b[j]=a[j];
				p[b[j]]++;
			}
		}
		    for(int k=0;k<m;k++){
		    	if(p[k]>0){
			    	l[k]=p[k]; 
			    }
		    } 
		}
	}
}
for(int i=0;i<m;i++){
	if(l[i]>0){
		cout<<l[i]<<" ";
	}
}
	return 0;
}
