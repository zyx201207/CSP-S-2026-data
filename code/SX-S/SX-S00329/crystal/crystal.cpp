#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],s[N],b[N],n,m,lst,cnt,num,js[N],res;
bool ok=false;

bool check(int x){
	if(!ok){
		while(a[++lst]<=x)cnt++;
	}else{
		while(a[--lst]>x)cnt--;
	}
	res=m-cnt*x+s[cnt];
	if(res>=0)return true;
	else return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	int len=unique(b,b+n)-b-1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int x=lower_bound(b,b+len,a[i])-b-1;
		js[x]++;
	}
	
	int l=a[1],r=a[n],ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
			ok=false;
		}else{
			r=mid-1;
			ok=true;
		}
//		cout<<"轮次:"<<l<<" "<<r<<" "<<ans<<" "<<cnt<<"\n";
	}
	
	
	int k=0;
	while(a[++k]<=ans)num++;
//	res=m-num*ans+s[num];
////	cout<<res<<'\n';
//	int kl=1,kr=num+1;
//	//整个区间向右拓展
//	while(1){
//		int x=lower_bound(b,b+len,a[kl])-b-1,y=lower_bound(b,b+len,a[kr])-b-1;
////		cout<<a[kl]<<" "<<js[x]<<" "<<a[kr]<<" "<<js[y]<<"\n";
//		if((ans-a[kl])*js[x]+res>=(num-js[x])*(a[kr]-ans)&&(js[x]<js[y])){
//			num=num-js[x]+js[y];
//			ans=a[kr];
//			kl+=js[x],kr+=js[y];
//			res=m-num*ans+(s[kr-1]-s[kl-1]);
//		}else{
//			break;
//		}
//	}
////	cout<<a[kl-1]<<" "<<kl<<" "<<a[kr-1]<<" "<<kr<<"\n";
////	cout<<res<<" "<<ans<<"\n";
//	//单独向左拓展
//	while(res>=0&&kl>=1){
//		if(res>=ans-a[--kl]){
//			num++;
//			res+=a[kl]-ans;
//		}
//	}
	cout<<num<<"\n";
	return 0;
}