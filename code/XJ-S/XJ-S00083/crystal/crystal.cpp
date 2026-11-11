#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10000005];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		if(a[i+1]<a[i]){
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	long long sum=0,num=0;
	for(int i=0;i<=n;i++){
		sum+=a[i];
	}
	num=sum/n;
	int b[10000005];
	for(int i=0;i<=n;++i){
		b[i]=num-a[i];
	}
	for(int j=0;j<=n;j++){
		if(b[j]>b[j+1]){
			int q=b[j];
			b[j]=b[j+1];
			b[j+1]=q;
		}
	}
	long long ans=0;
	for(int i=0;i<=10000000;i++){
		if(b[i]>0) m-=b[i];
		if(m>0){
			a[i]=num;
			ans++;
		}
		else if(m==0){
			cout<<ans;
			break;
		}
		else{
			ans-=1;
			m+=b[i];
		    int s=0,n=0;
			for(int i=0;i<=n;i++){
				s+=a[i];
			}
			n=s/n;
			int c[1000000];
			for(int i=0;i<=n;i++){
				c[i]=num-a[i];
			}
			for(int i=0;i<=n;i++){
				if(c[i]>c[i+1]){
					int d=c[i];
					c[i]=c[i+1];
					c[i+1]=d;
				}
			}
			for(int i=0;i<=100000;i++){
				if(c[i]>0) m-=c[i];
				if(m>0){
					a[i]=n;
					ans++;
				}
				else if(m==0){
					cout<<ans;
					break;
				}
			}
		}
	}
	return 0;
}
