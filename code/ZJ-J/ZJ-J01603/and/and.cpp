#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=-99999,mm=-99;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma){
			ma=a[i];
		}
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		for(int g=i;g<=n-m+1;g++){
			int x=a[g];
			for(int l=g+1;l<=g+m-1;l++){
				int y=a[l],k=x;
				if(x==y){
					if(x>mm){
						mm=x;
					}
					continue;
				}
				char xx[200005],yy[200005];
				int f=1,ff=1;
				while(k!=0){
					xx[f]==k%2;
					k/=2;
					f++;
				}
				while(y!=0){
					yy[ff]==y%2;
					y/=2;
					ff++;
				}
				int p=0,h=1;
				if(ff>f){
					f=ff;
				}
				for(int j=1;j<=f;j++){
					if(xx[j]=='1'&&yy[j]=='1'){
						p+=h;
					}
					h*=2;
				}
				mm=max(mm,p);
			}
		}
	}
	cout<<mm;
	return 0;
} 
