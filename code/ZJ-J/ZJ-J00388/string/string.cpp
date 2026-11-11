#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,a[N],b[N],e[N],f[N],len;
char c[N],d[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long mid,x,y,lt,lr;
	x=y=0;
	bool fl=false,o=(len%2==0);
	if(o){
		mid=len/2;
		for(int i=1;i<=n;i++){
			if(fl){
				b[++y]=a[i];
				d[y]=c[i];
				continue;
			}
			x+=a[i];
			if(x>=mid){
				fl=1;
				if(x>mid){
					b[++y]=x-mid;
					a[i]=mid-x+a[i];
					d[y]=c[i];
				}
				lt=i;
			}
		}
	}
	else{
		mid=len/2+1;
		for(int i=1;i<=n;i++){
			if(fl){
				b[++y]=a[i];
				d[y]=c[i];
				continue;
			}
			x+=a[i];
			if(x>=mid){
				fl=1;
				if(x>mid){
					b[++y]=x-mid+1;
					a[i]=mid-x+a[i];
					d[y]=c[i];
				}
				if(x==mid){
					b[++y]=1;
					d[y]=c[i];
				}
				lt=i;
			}
		}
	}
	lr=y;
	x=y=0;
	long long ans=0,cnt=0;
	for(int i=1;i<=lt;i++){
		e[i]=a[lt-i+1];
		x+=e[i];
	}
	for(int i=1;i<=lr;i++){
		f[i]=b[i];
		y+=b[i];
	}
	for(int i=1,j=1;i<=lt&&j<=lr;){
		if(c[lt-i+1]==d[j]){
			if(e[i]>=f[j]){
				e[i]-=f[j];
				j++;
				if(e[i]==0) i++;
			}
			else{
				f[j]-=e[i];
				i++;
			}
		}
		else{
			if(e[i]>=f[j]){
				e[i]-=f[j];
				cnt+=f[j];
				j++;
				if(e[i]==0) i++;
			}
			else{
				f[j]-=e[i];
				cnt+=e[i];
				i++;
			}
		}
	}
	ans=cnt;
	cout<<ans;
	return 0;
}
