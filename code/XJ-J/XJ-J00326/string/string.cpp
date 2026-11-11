#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,a[N],Gcd,rev[N],idx1=1,len,ans,hal[N],idx2=1;
char c[N],revc[N],halc[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(i==1) Gcd=a[i];
		else Gcd=__gcd(Gcd,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]/=Gcd;
		len+=a[i];
	}
	ll te=0;
	for(int i=n;i>=1;i--){
		if(te+a[i]<=len/2){
			rev[idx1]=a[i];
			revc[idx1]=c[i];
			idx1++;
			te+=a[i];
			if(te==len/2){
				idx1--;
				break;
			}
		}else{
			rev[idx1]=len/2-te;
			revc[idx1]=c[i];
			break;
		}
	}
	te=0;
	for(int i=1;i<=n;i++){
		if(te+a[i]<=len/2){
			hal[idx2]=a[i];
			halc[idx2]=c[i];
			idx2++;
			te+=a[i];
			if(te==len/2){
				idx2--;
				break;
			}
		}else{
			hal[idx2]=len/2-te;
			halc[idx2]=c[i];
			break;
		}
	}
	int i=1,j=1;
	while(1){
		if(revc[i]==halc[j]){
			if(rev[i]==hal[j]){
				i++,j++;
			}
			else if(rev[i]<hal[j]) hal[j]-=rev[i],i++;
			else rev[i]-=hal[j],j++;
		}else{
			if(rev[i]==hal[j]){
				ans+=rev[i];
				i++,j++;
			}
			else if(rev[i]<hal[j]) hal[j]-=rev[i],ans+=rev[i],i++;
			else rev[i]-=hal[j],ans+=hal[j],j++;
		}
		if(i>idx1&&j>idx2) break; 
	}
	cout<<ans*Gcd;
	return 0;
} 
