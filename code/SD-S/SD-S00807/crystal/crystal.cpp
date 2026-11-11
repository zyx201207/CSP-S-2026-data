#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005],cha[500005],he[500005],b[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		cha[i]=abs(a[i]-a[i+1]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n-1;j++){
		    he[j]=he[j-1]+cha[j];
		    b[j]+=he[j];
		    if(b[j]>m){
		    	break;
			}
	    }
	    for(long long j=i;j<=n-1;j++){
	    	he[j]=0;
		}
	}
	for(long long i=1;i<n;i++){
		if(m>=b[i]){
			ans=max(ans,i+1);
		}
		else{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
