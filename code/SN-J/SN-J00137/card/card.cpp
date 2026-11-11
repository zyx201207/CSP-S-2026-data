#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],z[500005],mun[300005],js=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(js<=n){
		int r=1,j=js,rs=0;
		while(j<=n){
			bool b=false;
			int zi;
			if (rs==0){
				z[r]=a[j];
				r+=1;
				rs+=1;
				j++;
			}
			else{
				j++;
			}
			for (int k=1;k<=rs;k++){
				if (a[j]==z[k]){
					b=true;
					zi=k;
				}
			}
			if (b==true){
				int rs1=rs,r1=r;
				r=zi;
				rs=zi-1;
				for (int k=zi;k<=rs1;k++){
					z[k]=0;
				}
				z[r]=a[j];
				r+=1;
				rs+=1;
			}
			if (b==false){
				z[r]=a[j];
				r++;
				rs++;
			}
		}
		for (int k=1;k<=rs;k++){
			mun[z[k]]++;
		}
		memset(z,0,sizeof(z));
		js++;
	}
		
	
	for (int i=1;i<=m;i++){
		cout<<mun[i]<<' ';
	}
		
	return 0;
}
