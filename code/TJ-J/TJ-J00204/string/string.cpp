#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int a[M];
char c[M];
long long sum[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	long long siz=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		siz+=a[i];
	}
	long long ans=0;
	int l=1,r=n;
	int prenow=0,backnow=siz;
	while(l<=r){
		int sumpre=sum[l]-prenow;
		int sumback=backnow-sum[r-1];
		if(sumpre>sumback){
			int now=sumback;
			prenow+=now;
			backnow-=now;
			if(c[l]!=c[r]){
				ans+=now;
			}
			r--;
		}
		else if(sumpre<sumback){
			int now=sumpre;
			prenow+=now;
			backnow-=now;
			if(c[l]!=c[r]){
				ans+=now;
			}
			l++;
		}
		else{
			int now=sumpre;
			prenow+=now;
			backnow-=now;
			if(c[l]!=c[r]){
				ans+=now;
			}
			l++;
			r--;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
