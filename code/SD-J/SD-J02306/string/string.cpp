#include<bits\stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],j,vis[50],sum[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		vis[c[i]-'a']++;
		if(i==n&&vis[c[i]-'a']==n){
			cout<<0;
			return 0;
		}
		sum[i]=sum[i-1]+a[i];
	}
	j=n;
	int i=1;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]){
				a[i]=0,a[j]=0;
				i++;
				j--;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]){
				a[i]=0,a[j]=0;
				i++,j--;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
	}
	for(int i=1;i<=n;i++)	ans+=a[i];
	int mid=sum[n]/2,kk;
	for(int i=1;i<=n;i++){
		if(sum[i]<=mid&&sum[i+1]>mid){
			kk=i;
			break;
		}
	}
	if(n%2==1)	cout<<ans-a[(n+1)/2];
	else	cout<<ans;
	return 0;
} 
