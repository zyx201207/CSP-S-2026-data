#include<bits/stdc++.h>
using namespace std;
long long int a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,k=0;cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i],b[i]=a[i];
	sort(a,a+n);
	sort(b,b+n);
	
	/*for(int i=1;i<n;i++){
		b[i]+=b[i-1];cout<<b[i]<<' ';
	}cout<<endl;
	for(long long int i=0;i<n;i++){
		long long int o=i*a[i]-b[i-1];
		cout<<o<<' ';
		if(o<=m)k=max(k,i+1);
		else{
			for(int j=0;j<n;j++){
				o-=(a[i]-a[j]);
				if(o<=m){
					k=max(i+1-j,k);
					break;
				}
			}
		}
	}cout<<k;*/
	for(int i=0;i<n;i++){
		long long int l=0,ll=0;
		for(int j=i-1;j>=0;j--){
			l+=a[i]-a[j];
			if(l<=m)ll++;
			k=max(k,ll+1);
		}
	}cout<<k;
	return 0;
} 
