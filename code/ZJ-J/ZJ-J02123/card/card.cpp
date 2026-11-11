#include<bits/stdc++.h>
using namespace std;
int n,m,p,f,i,j,k,a[500005],b[500005],v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	f=1;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f){
		for(i=0;i<n;i++){
			memset(b,0,sizeof b);
			for(j=i;j<n;j++){
				if(b[a[j]]==0){
					b[a[j]]=1;
					v[a[j]]++;
				}
			}
		}
	}
	else{
		for(i=0;i<n;i++){
			p=0;
			for(j=i;j<n;j++){
				f=-1;
				for(k=0;k<p;k++){
					if(a[j]==b[k]){
						f=k;
						break;
					}
				}
				if(f>=0){
					for(k=f+1;k<p;k++){
						b[k]=0;
					}
					p=f+1;
					continue;
				}
				b[p++]=a[j];
			}
			for(j=0;j<p;j++){
				v[b[j]]++;
			}
		}
	}
	for(i=0;i<m;i++){
		cout<<v[i+1]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}