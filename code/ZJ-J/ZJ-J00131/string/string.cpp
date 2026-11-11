#include<bits/stdc++.h>
using namespace std;
int n,a[200005],q[200005],h[200005];
char c[200005],sq[200005],sh[200005];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l=0,j=1,last;
	while(l<sum/2){
		q[j]=a[j];
		sq[j]=c[j];
		l+=a[j];
		j++;
	}
	if(l>sum/2){
		last=l-sum/2;
		q[j]=last;
		sq[j]=c[j];
	}
	int r=sum,k=n;
	while(r>sum/2){
		h[k]=a[k];
		sh[k]=c[k];
		r-=a[k];
		k--;
	}
	if(r<sum/2){
		last=sum/2-l;
		h[k]=last;
		sh[k]=a[k];
	}
	int j1=1,k1=n;
	while(j1<=k1){
		if(sq[j1]!=sh[k1]){
			if(q[j1]<h[k1]) ans+=q[j1];
			else ans+=h[k1];
		}
		if(q[j1]<h[k1]){
			h[k1]-=q[j1];
			j1++;
		}
		else if(q[j1]==h[k1]){
			k1--;
			j1++;
		}
		else{
			q[j1]-=h[k1];
			k1--;
		}
	}
	for(j1;j1<j-1;j1++) ans+=q[j1];
	for(k1;k1>k+1;k1--) ans+=h[k1];
	cout<<ans;
	return 0;
}
