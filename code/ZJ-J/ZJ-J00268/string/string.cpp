#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	char c;
	int s;
}a[N],b[N],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		sum+=a[i].s;
	}
	int k=0;
	if(sum%2==1){
		k=1;
	}
	sum/=2;
	int z,ans=0;
	for(int i=1;i<=n;i++){
		if(ans+a[i].s>sum){
			b[i].c=a[i].c;
			b[i].s=sum-ans;
			a[i].s-=sum-ans+k;
			z=i;
			break;
		}
		b[i]=a[i];
		ans+=a[i].s;
		
	}
	for(int i=n;i>=z;i--){
		c[n-i+1]=a[i];
	}
	int num=0,j=1;
	for(int i=1;i<=n;i++){
		if(b[i].s==0) continue;
		while(b[i].s&&j<=n){
			if(b[i].c==c[j].c){
				if(b[i].s>c[j].s){
					num+=c[j].s;
					b[i].s-=c[j].s;
					j++;
				}else{
					num+=b[i].s;
					c[j].s-=b[i].s;
					break;
				}
			}else{
				if(b[i].s>c[j].s){
					b[i].s-=c[j].s;
					j++;
				}else{
					c[j].s-=b[i].s;
					break;
				}
			}
		}
	}
	cout<<sum-num;
	return 0;
}

