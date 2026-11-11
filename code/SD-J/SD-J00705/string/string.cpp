#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,mid,m,k,kk,kkk,la,lb,laa,lbb;
ll a[200005],b[200005];
char c[200005],cc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
//		cout<<i<<" "<<a[i]<<"\n";
	}
	m=a[n];
	mid=a[n];
	mid/=2;
//	cout<<mid<<"\n";
	for(int i=1;i<=n;i++){
		if(a[i]>mid){
			k=i-1;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[n]-a[i-1]>mid){
			kk=i+1;
			break;
		}
	}
	for(int i=1,j=n;j>=kk;i++,j--){
		b[i]=b[i-1]+a[j]-a[j-1];
		cc[i]=c[j];
		kkk=i;
	}
	swap(kkk,kk);
//	cout<<k<<" "<<kk<<"\n";
	if(k+kk<n){
		k++;
		kk++;
		a[k]=mid;
		b[kk]=a[k];
		cc[kk]=c[k];
	}
//	for(int i=1;i<=k;i++){
//		cout<<a[i]<<" "<<c[i]<<"\n";
//	}
//	cout<<"\n\n";
//	for(int i=1;i<=kk;i++){
//		cout<<b[i]<<" "<<cc[i]<<"\n";
//	}
	ll l=1,r=1;
	while(l<=k && r<=kk){
		la=a[l-1]+1;
		lb=b[r-1]+1;
		laa=a[l];
		lbb=b[r];
		if(c[l]!=cc[r]){
			ans+=min(laa,lbb)-max(la,lb)+1;
		}
		if(laa<lbb){
			l++;
		}else if(lbb<laa){
			r++;
		}else{
			l++;
			r++;
		}
	} 
	cout<<ans;
	return 0;
}
//luogu_liuyuxiaozaizai

