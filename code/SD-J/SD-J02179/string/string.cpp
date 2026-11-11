#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,len,ans;
ll a[200010];
char c[200010];
ll h,t,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>n;
	h=1,t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	l=0,r=len+1;
	while(l<=(len/2)&&r>=((len+1)/2)){
		if(c[h]==c[t]){
			if(a[h]>a[t]){
				a[h]-=a[t];
				l+=a[t];
				r-=a[t];
				t--;
			}
			else if(a[h]==a[t]){
				l+=a[h];
				r-=a[t];
				h++;
				t--;
			}
			else{
				a[t]-=a[h];
				l+=a[h];
				r-=a[h];
				h++;
			}
		}
		else{
			if(a[h]>a[t]){
				a[h]-=a[t];
				l+=a[t];
				r-=a[t];
				if(l<=(len/2)&&r>=((len+1)/2)) ans+=a[t];
				t--;
			}
			else if(a[h]==a[t]){
				l+=a[h];
				r-=a[t];
				if(l<=(len/2)&&r>=((len+1)/2)) ans+=a[t];
				h++;
				t--;
			}
			else{
				a[t]-=a[h];
				l+=a[h];
				r-=a[h];
				if(l<=(len/2)&&r>=((len+1)/2)) ans+=a[h];
				h++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
