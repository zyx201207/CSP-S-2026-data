#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],ans,c,f=1,qwerty;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qwerty++;
	}
	sort(a+1,a+n+1);
	c=a[2]-a[1];
	for(int i=2;i<=n;i++){
		qwerty++;
		if(a[i]-a[i-1]!=c){
			f=0;
		}
	}
	if(f){
		long long k=0;
		for(int i=1;i<=n;i++){
			qwerty++;
			k+=i*c;
			if(k>m){
				cout<<i-1;
				break;
			}
		}
		return 0;
	}
	for(long long i=n;i>=1&&i>ans;i--){
		if(qwerty>9e7){
			cout<<ans;
			return 0;
		}
		long long s=m,cnt=0;
		for(int j=i;j>=1&&j+cnt>ans;j--){
			qwerty++;
			if(s>=a[i]-a[j]){
				s-=a[i]-a[j],cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
//Ë«ÖØÑ­»·+ÌØÊâÅÐ¶Ï£¬70~80 
