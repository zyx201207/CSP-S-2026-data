#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long n,m,a[N],down=1,ans,maxx,nn,mm;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	nn=n,mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<=5000&&m<=1000000000){
		long long i=1;
		while(nn--){
			for(int j=i;j<n;j++){
				if(a[j]!=a[j+1]){
					m-=down*(a[j+1]-a[j]);
					if(m>=0)a[j]=a[j+1];
				}
					while(a[j]==a[j+1]){
						down++;
						ans++;
						j++;
					}
					j--;
				if(m<=0||a[n-1]==a[n]){
					break;
				}
			}
			maxx=max(maxx,ans+1);
			i++;
			ans=0;
			m=mm;
			down=1;
		}
		ans=maxx;
	}else{
		for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			m-=down*(a[i+1]-a[i]);
			ans++;
		}else{
			down++;
			ans++;
		}
		if(m<=0||a[n-1]==a[n]){
			break;
		}
		}
	}
	cout<<ans;
	return 0;
}
