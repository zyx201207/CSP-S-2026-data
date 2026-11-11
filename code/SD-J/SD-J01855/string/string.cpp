#include<bits/stdc++.h>
using namespace std;
const int N=2e5+105;
int n,a[N],rest,op,cnt2;
char c[N],cnt='0';
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(i>(n-i+1+op))break;
		else if(i==(n-i+1+op)){
			if(rest){
				if(cnt==c[i]){
					break;
				}
				else {
					ans+=min(rest,a[i]);
					break;
				}
			}
		}
		if(cnt!='0'&&rest){
			if(rest>a[i]){
				if(c[i]==cnt){
					rest-=a[i];
					if(cnt2==12)op++;
					else op--;
					continue;
				}
				else {
					ans+=a[i];
					rest-=a[i];
					if(cnt2==12)op++;
					else op--;
					continue;
				}
			}
			else {
				if(c[i]==cnt){
					rest=0;
					a[i]-=rest;
				}
				else {
					ans+=rest;
					a[i]-=rest;
				}
			}
		}
		if(c[i]==c[n-i+1+op]){
			if(a[i]!=a[n-i+1+op]){
				if(a[i]>a[n-i+1+op]){
					rest=(a[i]-a[n-i+1+op]);
					cnt=c[i];
					cnt2=11;
				}
				else {
					rest=a[n-i+1+op]-a[i];
					cnt=c[n-i+1+op];
					cnt2=12;
				}
			}
			else {
				rest=0;
				cnt='0';
			}
		}
		else {
			ans+=min(a[i],a[n-i+1+op]);
			if(a[i]>a[n-i+1+op]){
					rest=(a[i]-a[n-i+1+op]);
					cnt=c[i];
					cnt2=11;
			}
			else {
				rest=a[n-i+1+op]-a[i];
				cnt=c[n-i+1+op];
				cnt2=12;
			}
		}
	}
	cout<<ans;
	return 0;
} 
