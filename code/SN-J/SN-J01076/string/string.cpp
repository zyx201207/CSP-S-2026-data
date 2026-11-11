#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n; 
ll a[N];//统计这个部分有多少个字符 
char c[N];//这个部分内的字符是什么 
ll sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	ll l=1,r=(sum+1)/2,ans=0,mid=0,su=0;
	for(int i=1;i<=n;i++){
		su+=a[i];
		if(su>mid){
			mid=i;
		}
	}
	for(int i=1,j=n;i<=mid-2&&j>=mid-2;){
		ll l1=a[i];
		ll l2=a[j];
		if(c[i]==c[j]){
			if(l1<l2){
				a[j]-=l1;
				a[i]=0;
				i++;
			}else if(l1==l2){
				a[j]=0;
				a[i]=0;
				j--;
				i++;
			}else{
				a[j]=0;
				j--;
				a[i]-=l2;
			}
		}else{
			ans+=min(l1,l2);
			if(l1<l2){
				a[j]-=l1;
				a[i]=0;
				i++;
			}else if(l1==l2){
				a[j]=0;
				a[i]=0;
				j--;
				i++;
			}else{
				a[j]=0;
				j--;
				a[i]-=l2;
			}
		}
	}
	cout<<ans;
	return 0;
}
