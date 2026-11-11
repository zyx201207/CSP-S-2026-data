#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,a[N],len,mid,cnt;
string s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	mid=(len+1)>>1;
	ll i=1,j=n;
	ll l=a[1],r=a[n];
	ll la=a[i],ra=a[j];
	while(l<=mid){
		char lc=c[i],rc=c[j];
		string s1,s2;
		if(l<r){
			if(lc==rc){
				ra-=la;
				i++;
				la=a[i];
				l+=a[i]; 
				if(l>mid){
					la=la-2*(l-mid);
				}
			}
			else{
				cnt+=la;
				ra-=la;
				i++;
				la=a[i];
				l+=a[i];
				if(l>mid){
					la=la-2*(l-mid);
				}
			}
		}
		else{
			if(lc==rc){
				j--;
				la-=ra;
				ra=a[j];
				r+=a[j];
				if(r>mid){
					ra=ra-2*(r-mid);
				}
			}
			else{
				cnt+=ra;
				la-=ra;
				j--;
				ra=a[j];
				r+=a[j]; 
				if(r>mid){
					ra=ra-2*(r-mid);
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}  
