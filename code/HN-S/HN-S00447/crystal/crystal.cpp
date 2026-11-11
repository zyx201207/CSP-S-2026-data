#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],fn,p,ans=1;
void f(int l,int r){//find
	if(r-l==1){
		fn=a[l],p=l;
		return;
	}
	long long t;
	int mid=(l+r)/2;
	for(int i=l;i<r;i++) t+=a[i];
	t=(t+0.5)/(r-l);
	if(a[mid]>t) f(mid,r);
	else if(a[mid]<t) f(l,mid);
	else fn=t,p=mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	f(0,n);
	
	int i=(p>0?p-1:0),j=(p<n-1?p+1:n-1);
	for(int t=0;t<n-1;t++){
		if(fn-a[i]<=a[j]-fn&&i>=0){
			if(m-fn+a[i]>=0) m-=fn-a[i],i--,ans++;
			else break;
		}
		if(fn-a[i]>a[j]-fn&&j<n){
			if(m-a[j]+fn>=0) m-=a[j]-fn,j++,ans++;
			else break;
		}
	}
	if(m>0){
		while(i>0) if(m-fn+a[i]>=0) m-=fn-a[i],i--,ans++;
		while(j<n-1) if(m-a[j]+fn>=0) m-=a[j]-fn,j++,ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
