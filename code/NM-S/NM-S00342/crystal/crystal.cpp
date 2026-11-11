#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],lk[500005],sh,ges,hua,ka,ges1=0;
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		lk[i]=a[i+1]-a[i];
		sh+=lk[i];
	}
	while(f==false){
		ka++;
		if(lk[ka]<=m){f=true;ges=1;}
	}
	int ka1=ka;
	for(int i=ka1;i<n;i++){
		if(hua+lk[i]*ges<=m){hua+=lk[i]*ges;ges++;}
		else{
			if(lk[ka]>=lk[i]*(ges-1)&&hua-lk[ka]+lk[i]*(ges-1)<=m){hua-=lk[ka];hua+=lk[i]*(ges-1);ka++;}
			else if(lk[i]>=m){ges1=max(ges,ges1);ges=1;hua=0;ka=i+1;}
			else{
				ges1=max(ges,ges1);
				while(hua+lk[i]*(ges-1)>m){hua-=lk[ka];ges--;ka++;}
				ges++;
				hua+=lk[i]*(ges-1);
			}
		}
	}
	cout<<max(ges,ges1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
