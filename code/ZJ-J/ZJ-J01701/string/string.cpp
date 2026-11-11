#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005][3],b=0,n=0;
ll sum=0,ans=0;
char x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i][0]>>x;
    	a[i][1]=x;
	}
	ll m=n/2;
	for(int i=1;i<=m;i++){
		sum=a[i][0];
		for(int j=n;j>=m+1;j--){
			if(a[i][1]==a[j][1]&&sum>=a[j][0]){
				sum-=a[j][0];
				n--;
			}else if(a[i][1]!=a[j][1]&&sum>=a[j][0]){
				ans+=a[j][0];
				sum-=a[j][0];
				n--;
			}else if(a[i][1]==a[j][1]&&sum<a[j][0]){
				a[j][0]-=sum;
				break;
			}else if(a[i][1]!=a[j][1]&&sum<a[j][0]){
				a[j][0]-=sum;
				ans+=sum;
				break;
			}
		}
	}
	cout<<ans;
    return 0;
}