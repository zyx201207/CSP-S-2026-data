#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],bs,ans;
int ac[200010];
char c[200010];
struct dd{
	int qb;
	char cp;
}hd[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ac[i]>>c[i];
		a[i]=a[i-1]+ac[i];	
	}
	long long zs=a[n];
	int ks;
	for(int i=1;i<=n;i++){
		if(a[i]>=zs/2){
			ks=i;
			break;
		}
	}
	if(a[ks]>zs/2&&(zs+1)/2!=a[ks]){
		for(int i=n;i>ks;i--){
			hd[n-i+1].cp=c[i];
			hd[n-i+1].qb=ac[i];	
		}
		hd[n-ks+1].cp=c[ks];
		hd[n-ks+1].qb=zs/2;
		ac[ks]=a[ks]-zs/2;
		bs=n-ks+1;
	}
	else{
		for(int i=n;i>ks;i--){
			hd[n-i+1].cp=c[i];
			hd[n-i+1].qb=ac[i];	
		}
		if(zs%2){
			if(a[ks]==zs/2) hd[n-ks].qb--;	
			else ac[ks]--;
			bs=n-ks;
		}
	}
	long long zss=0;
	int i=1,j=1;
	while(zss!=zs/2){
		if(c[i]==hd[j].cp){
			zss+=min(ac[i],hd[j].qb);
			if(ac[i]>hd[j].qb){
				ac[i]-=hd[j].qb;
				j++;
			}
			else{
				hd[j].qb-=ac[i];
				i++;
			}
		}
		else{
			zss+=min(ac[i],hd[j].qb);
			ans+=min(ac[i],hd[j].qb);
			if(ac[i]>hd[j].qb){
				ac[i]-=hd[j].qb;
				j++;
			}
			else{
				hd[j].qb-=ac[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
