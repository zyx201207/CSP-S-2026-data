#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],l[35],maxx,r[35];
bool f,f1,f2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<30;i++) l[i]=(1<<i)-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool xx=0;
		for(int j=0;j<30;j++) if(a[i]==l[j]) xx=1;
		if(a[i]!=i-1) f2=1;
		if(xx==0) f1=1;
		if(a[i]>=4) f=1;
		maxx=max(maxx,a[i]);
	}
	if(f==0){
		long long x[5]={};
		for(int i=1;i<=n;i++)	x[a[i]]++;
		if(x[3]>=m)	cout<<3;
		else if(x[2]+x[3]>=m) cout<<2;
		else if(x[1]+x[3]>=m) cout<<1;
		else cout<<0;
		//10 a[i]<4
	}
	else if(m==1){
		cout<<maxx;
		//5
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		//5
	}
	else if(m==2){
		long long max1=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max1=max(max1,a[i]&a[j]);
			}
		}
		cout<<max1;
		//15
	}
	else if(!f1){
		for(int i=1;i<=n;i++){
			for(int j=0;j<30;j++) if(a[i]==l[j]) r[j]++;
		}
		int s=0;
		for(int i=30-1;i>=0;i--){
			s+=r[i];
			if(s>=m){
				cout<<l[i];
				return 0;
			}
		}
		//5 A
	}
	else if(!f2){
		if(m<=n/2){
			int ans=0;
			while(m<=n/2){
				ans+=n/2;
				n/=2;
			}
			cout<<ans;
		}
		else{
			cout<<0;
		}
		//10 B
	}
	else{
		bool vis[200]={};
		long long anss=0;
		for(int i=1;i<=n;i++){
			long long now=i;
			vis[i]=1;
			for(int j=2;j<=m;j++){
				long long max3=0,id=0;
				for(int k=1;k<=n;k++){
					if(!vis[i]&&(now&a[k])>max3){
						max3=max(max3,now&a[k]);
						id=k;
					}
				}
				vis[id]=1;
				now=max3;
			}
			for(int i=1;i<=n;i++){
				vis[i]=0;
			}
			anss=max(anss,now);
		}
		cout<<anss;
		//25
	}
	return 0;
}
