#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll n,m,a[N],small=1e9,big=-1e9,sum,cnt,ans,b[N];
bool flag=1,flag1=1; 
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll gx=a[2]-a[1];
		cin>>a[i];
		 small=min(small,a[i]);
		big=max(big,a[i]);
		if(a[i]!=i)flag=0;
		if(a[i]-a[i-1]!=gx&&i>=2)flag1=0;
	}
	if(flag){
		for(ll i=1;i<=n;i++){
			b[i]=b[i-1]+i-1;
			if(b[i]>m){
				cout<<b[i-1];
				return 0;
			}
		} 
	}
	for(ll i=small;i<=big;i++){
		cnt=0;
		sum=m;
		for(ll j=1;j<=n;j++){
			b[j]=0;
		}
		for(ll j=1;j<=n;j++){
			if(a[j]<=i){
				b[j]=i-a[j];
			}
			else{
				b[j]=1e9;
			}
		}
		sort(b+1,b+1+n);
		for(ll j=1;j<=n;j++){
			if(sum-b[j]>=0){
				sum-=b[j];
				cnt++;
			}
		}	
		ans=max(ans,cnt);
	//	cout<<cnt<<endl;
	}
cout<<ans;//	<<big<<small;
	return 0;
} 
