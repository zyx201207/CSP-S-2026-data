#include<bits/stdc++.h>
using namespace std;
const int C=5e5+5;
long long n,m,a[C],sum=1,ans,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;){
		if(i>=n){
			break;
		}
		c=(a[i+1]-a[i])*(i-j+1);
		if(ans+c<=m){
			while(ans<=m&&i<n){
				c=(a[i+1]-a[i])*(i-j+1);
				if(ans+c<=m){
					ans+=c;
					i++;
					sum=max(sum,(long long)(i-j+1));
				}else{
					break;
				}
			}
			if(i>n){
				break;
			}
		}else{
			if(i==j){
				ans=0;
				i++,j++;
				continue;
			}
			c=a[i]-a[j];
			ans-=c;
			c=(a[i+1]-a[i])*(i-j);
			ans+=c;
			j++,i++;
		}
	}
	cout<<sum<<'\n';
	return 0;
}