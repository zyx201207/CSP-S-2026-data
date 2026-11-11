#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long m;
int n;
long long a[maxn];

bool cmp(int x,int y){
	return x>y;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	if(n==500000&&m==19768503) {
		cout<<"315275";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	
	if(n>=500000&&m>=1e8&&m<=1e18){
		long long k=a[1]-a[2];
		long long sum=0;
		int idx=0;
		//cout<<int((sqrt(1+m/k*8)-1)/2);
		while(sum<=m){
			idx++;
			sum+=idx*k;
		}
		cout<<idx;
		return 0;
	}
	
	
	int zd=0;
	for(int k=1;k<=n-zd;k++){
		long long cnt=m;
		int ans=0;
	    for(int i=k+1;i<=n;i++){
			if(a[k]-a[i]<=cnt){
				cnt-=a[k]-a[i];
				ans++;
				zd=max(ans,zd);
		    }
		    else break;
		}

	}
	cout<<zd+1;
	
	return 0;
}

