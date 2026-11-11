#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
	freopen("and.in","r",stdin);//I love CCF
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int o=a[1];
		for(int i=2;i<=n;i++){
			o=o&a[i];
		}
		cout<<o<<endl;
	}else if(m==1){
		int maxe=-1;
		for(int i=1;i<=n;i++){
			if(maxe<=a[i]){
				maxe=a[i];
			}
		}
		cout<<maxe<<endl;
	}else{
		long long maxe=-1,maxi=0,maxc,mo=m;
		while(1){
			for(int i=1;i<=n;i++){
				if(maxe<=a[i]){
					maxe=a[i];
					maxi=i;
				}
			}
			if(mo==m){
				maxc=maxe;
			}else{
				maxc=maxc&maxe;
			}
			a[maxi]=-1;
			maxe=-1;
			mo--;
			if(mo==0){
				break;
			}
		}
		cout<<maxc<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
