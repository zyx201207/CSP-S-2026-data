#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
const int N=5e5+5;
ll n,sum[N],mid,mi,b[N],ans,sub[N];
ll a[N];char ch[N],bb[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(re int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum[i]=sum[i-1]+a[i];
	}
	mi=(sum[n]+1)/2;
	//cout<<mi<<endl;
	for(re int i=1;i<=n;i++){
		if(sum[i]>=mi){
			mid=i;
			break;
		}
	}
	for(re int i=n;i>mid;i--){
		b[n-i+1]=a[i];
		bb[n-i+1]=ch[i];
	}
	b[n-mid+1]=sum[mid]-mi+(sum[n]%2==1);
	bb[n-mid+1]=ch[mid];
	a[mid]=mi-sum[mid-1];
	sum[mid]=sum[mid-1]+a[mid];
	for(int i=1;i<=n-mid+1;i++){
		sub[i]=b[i]+sub[i-1];
	}
	ll r=1,rs=b[1],l=1,ls=a[1],now=0;
	//for(re int i=1;i<=max(mid,n-mid+1);i++){
	//	cout<<a[i]<<ch[i]<<sum[i]<<' '<<b[i]<<bb[i]<<sub[i]<<endl;
	//}
	//cout<<sub[n-mid]<<endl;
	while(now<mi){
		if(sum[l]>=sub[r]){
			ans+=(sub[r]-now)*(bb[r]!=ch[l]);
			now=sub[r];
			r++;
		}
		else{
			ans+=(sum[l]-now)*(bb[r]!=ch[l]);
			now=sum[l];
			l++;
		}
		//cout<<now<<' '<<ans<<endl;
		//if(now==0)break;
	}
	cout<<ans<<endl;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
