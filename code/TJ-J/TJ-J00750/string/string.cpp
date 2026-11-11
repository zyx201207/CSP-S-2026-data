#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005]={},sum=0,sumn=0,r=0,l=0,rca[100005]={},lca[100005]={},cntr=1,cntl=1,cnt=0;
	string c,cacr,cacl;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0; 
	}
	if(n==2){
		cin>>a[0];
		cin>>c[0];
		cin>>a[1];
		cin>>cacr[0];
		if(c[0]!=cacr[0])
		cout<<abs(a[0]-a[1]);
		else{
			cout<<"0";
		} 
		return 0;
	} 
	else if(n<=2000) {
	for(int i=0;i<n;i++){
		cin>>r;
		cin>>cacr[0];
		for(int j=0;j<r;j++){
			c[cnt++]=cacr[0];
		}
	} 
	cntr=cnt-1;
	for(int i=0;i<=(cnt-1)/2;i++){
		if(c[i]!=c[cntr]){
			sum+=1;
		} 
	}
	cout<<sum;
	return 0;
	}
	else{
		int cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
	}
	for(int i=1;i<=sum/2;i++){
		if(a[i]==a[cnt]){
			if(c[i]==c[cnt]&&r==0&&l==0){
				sumn+=0;
			}
			else if(c[i]!=c[cnt]&&r==0&&l==0){
				sumn+=a[i];
			}
			else if(r!=0||l!=0){
				if(r!=0){
					if(cntr==2)
					{
						if(a[i]>=rca[cntr]+a[cnt]){
							if(cacr[cntr]!=c[i]&&c[cnt]!=c[i]){
								sumn+=a[cnt]+rca[cntr];
								l=a[i]-a[cnt]-rca[cntr];
								lca[cntl]=l;
								cacl[cntl]=c[i];
								r=0;
								cntr=1;
							}
							else if(cacr[cntr]!=c[i]&&c[cnt]==c[i]){
								sumn+=rca[cntr];
								l=a[i]-a[cnt]-rca[cntr];
								lca[cntl]=l;
								cacl[cntl]=c[i];
								r=0;
								cntr=1;
							}
							else{
								l=a[i]-a[cnt]-rca[cntr];
								lca[cntl]=l;
								cacl[cntl]=c[i];
								r=0;
								cntr=1;
							}
						}
						else if(a[i]>=rca[cntr]){
							if(cacr[cntr]!=c[i]&&c[cnt]!=c[i]){
								sumn+=a[i];
								cacr[cntr]=c[cnt];
								r=abs(a[i]-a[cnt]-rca[cntr]);
								cntr=2;
							}
							else if(cacr[cntr]!=c[i]&&c[cnt]==c[i]){
								sumn+=(a[i]-(a[i]-cacr[cntr]));
								cacr[cntr]=c[cnt];
								r=abs(a[i]-a[cnt]-rca[cntr]);
								cntr=2;
							}
							else{
								cacr[cntr]=c[cnt];
								r=abs(a[i]-a[cnt]-rca[cntr]);
								cntr=2;
							}
						}
						else{
							if(cacr[cntr]!=c[i]){
								sumn+=a[i];
								cacr[cntr]=c[cnt];
								r=abs(a[i]-a[cnt]-rca[cntr]);
								cntr=2;
							}
							else{
								cacr[cntr]=c[cnt];
								r=abs(a[i]-a[cnt]-rca[cntr]);
								cntr=2;
							}	
						}
					}
				}
			}
		}
		else{
			if(a[i]<=a[cnt]){
				if(r==0&&l==0){
					sumn+=a[cnt]-a[i];
				}
			}
			else{
				if(r==0&&l==0){
					sumn+=a[i]-a[cnt];
				}	
			}
		}
	}
	}
	return 0;
} 
