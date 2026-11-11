#include<bits/stdc++.h>
using namespace std;
long long n,ans,len;
//jia;
struct sp{
	long long k;
	char hj;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long i;
	//jia=n;
	for(i=1;i<=n;i++){
		cin>>a[i].k;
		cin>>a[i].hj;
		if(a[i].hj==a[i-1].hj){
			a[i-1].k+=a[i].k;
			i--;
			n--;
			//jia--;
		}
	}long long l=1,kl;
	kl=i;
	while(l<kl){
		if(a[l].hj==a[kl].hj){
			if(a[l].k==a[kl].k){
				l++;
				kl--;
			}else if(a[l].k>a[kl].k){
				a[l].k-=a[kl].k;
				kl--;
			}else{
				a[kl].k-=a[l].k;
				l++;
			}
		}else{
			if(a[l].k==a[kl].k){
				ans+=a[l].k;
				l++;
				kl--;
			}else if(a[l].k>a[kl].k){
				a[l].k-=a[kl].k;
				ans+=a[kl].k;
				kl--;
			}else{
				a[kl].k-=a[l].k;
				ans+=a[l].k;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
