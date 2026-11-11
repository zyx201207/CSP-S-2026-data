#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],k,ans,num;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
    	//cout<<i-1<<" "<<a[i]-a[i-1]<<" "<<k<<"\n";
    	if(k+(i-1)*(a[i]-a[i-1])<=m){
    		k+=(i-1)*(a[i]-a[i-1]);
		}
		else{
			break;
	    }
	    ans=i;
	}
	for(int i=n-1;i>=1;i--){
    	//cout<<i-1<<" "<<a[i]-a[i-1]<<" "<<k<<"\n";
    	if(k+(n-i+1)*(a[i+1]-a[i])<=m){
    		k+=(n-i+1)*(a[i+1]-a[i]);
		}
		else{
			break;
	    }
	    num=n-i;
	}
	cout<<max(num,ans);
    return 0;
}

