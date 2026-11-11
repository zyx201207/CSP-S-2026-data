#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
char s[N];
ll sum,mx;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char b;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
		if(i==1) b=s[i];
		else{
			if(s[i]!=b) f=1;
		}
		mx=max(mx,a[i]);
	}
	if(!f){
		cout<<0;
		return 0;
	}
	if(mx*n<=200000000){
		ll ans=0;
		string ss="";
		ll x=(sum+1)/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++) ss+=s[i];
		}
//		cout<<ss;
		for(int i=x-1,j=x+1;i>=1 && j<=sum;i--,j++){
			if(ss[i-1]!=ss[j-1]) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(sum%2==1){
		ll ans=0;
		ll ss=0;
		ll x=(sum+1)/2;
		ll pos=-1;
		for(int i=1;i<=n;i++){
			ss+=a[i];
			if(ss>=x){
				pos=i;
				break;
			}
		}
		ll l=0;
		for(int i=1;i<pos;i++) l+=a[i];
		l=x-l-1;
		ll r=a[pos]-l-1;
		if(l>r){
			ans+=l-r;
			a[pos+1]-=(l-r);
			a[pos]-=(l-r);
		}else{
			ans+=r-l;
			a[pos-1]-=(r-l);
			a[pos]-=(r-l);
		}
//		cout<<l<<" "<<r<<" "<<pos<<"\n";
		for(int i=pos-1,j=pos+1;i>=1 && j<=n;){
			if(a[i]>a[j]){
				if(s[i]!=s[j]){
					ans+=a[i]-a[j];
					a[i]-=(a[i]-a[j]);
				}else{
					a[i]-=(a[i]-a[j]);
				}
				j++;
			}else if(a[i]<a[j]){
				if(s[i]!=s[j]){
					ans+=a[j]-a[i];
					a[j]-=(a[j]-a[i]);
				}else{
					a[j]-=(a[j]-a[i]);
				}
				i--;
			}else{
				if(s[i]!=s[j]) ans+=a[i];
				a[i]=0;
				a[j]=0;
				i--,j++;
			}
		}
		cout<<ans;
	}else{
		ll ans=0;
		ll ss=0;
		ll x=sum/2;
		ll pos=-1;
		for(int i=1;i<=n;i++){
			ss+=a[i];
			if(ss>=x){
				pos=i;
				break;
			}
		}
//		cout<<pos<<"\n";
		for(int i=pos,j=pos+1;i>=1 && j<=n;){
			if(a[i]>a[j]){
				if(s[i]!=s[j]){
					ans+=a[i]-a[j];
					a[i]-=(a[i]-a[j]);
				}else{
					a[i]-=(a[i]-a[j]);
				}
				j++;
			}else if(a[i]<a[j]){
				if(s[i]!=s[j]){
					ans+=a[j]-a[i];
					a[j]-=(a[j]-a[i]);
				}else{
					a[j]-=(a[j]-a[i]);
				}
				i--;
			}else{
				if(s[i]!=s[j]) ans+=a[i];
				a[i]=0;
				a[j]=0;
				i--,j++;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
