#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,h=0;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	if(cnt%2==1){
		cnt++;
		cnt/=2;
		long long ans=cnt;
		for(int i=1;;i++){
			if(ans<a[i]){
				ans-=1;
				long long d=a[i]-ans-1;
				a[i]=max(d,ans)-min(d,ans);
				if(d>ans){
					h=i-1;
				}
				else if(d<ans){
					h=i;
				}
				else{
					n--;
					h=i-1;
				}
				break;
			}
			else if(ans==a[i]){
				a[i]-=1; 
				h=i;
				break;
			}
			else{
				ans-=a[i];
			}
		}
	}
	else{
		cnt/=2;
		long long ans=cnt;
		for(int i=1;;i++){
			if(ans<a[i]){
				long long d=a[i]-ans;
				a[i]=max(d,ans)-min(d,ans);
				if(d>ans){
					h=i-1;
				}
				else if(d<ans){
					h=i;
				}
				else{
					n--;
					h=i-1;
				}
				break;
			}
			else if(ans==a[i]){
				h=i;
				break;
			}
			else{
				ans-=a[i];
			}
		}
	}
	long long daan=0;
	for(int i=1,lst=n;i<=h&&lst>=h+1;){
		if(c[i]!=c[lst]){
			daan+=min(a[i],a[lst]);
		}
		if(a[i]>a[lst]){
			a[i]=a[i]-a[lst];
			a[lst]=0;
			lst--;
		} 
		else if(a[i]<a[lst]){
			a[lst]=a[lst]-a[i];
			a[i]=0;
			i++;
		}
		else{
			a[i]=0;
			a[lst]=0;
			lst--;
			i++;
		}
	}
	cout<<daan;
	return 0;
}
