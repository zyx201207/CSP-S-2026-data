#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,a[50030],b[50030],maxn=-99999,ans=0,l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l;
		a[i]=l;
		b[i]=0;
	}
	sort(a+1,a+n+1);
	int tol=0;
	for(int i=2;i<=n;i++){
		b[i]=tol+a[i]-a[i-1];
		tol=b[i];
	} 
	for(int i=n;i>1;i--){
		long long sum=0,ans=0,flag=1;
		for(int j=i-1;j>=1;j--){
			sum+=b[i]-b[j];
			if(sum>m){
				int t1=i,t2=j;
				ans=t1-t2+1;
				maxn=max(maxn,ans);
				flag=0;
				break;
			}
			if(flag){
				int t1=i,t2=j;
				ans=t1-t2+1;
				maxn=max(maxn,ans);
			}
		}
	}
	cout<<maxn<<endl;	
	return 0;
}