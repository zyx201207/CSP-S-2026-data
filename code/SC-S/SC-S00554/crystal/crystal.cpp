#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N],suo[N],b[N];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long now=a[1];
	suo[1]=a[1];
	int l=1;
	b[1]=1;
	for(int i=2;i<=n;i++){
		if(now!=a[i]){
			l++;
			b[l]=i;
			suo[l]=a[i];
			now=a[i];
		}
	}
	b[l+1]=n+1;
	suo[l+1]=0x3f3f3f3f;
	long long tm=m;
	for(int i=1;i<=l;i++){
		long long cnt=b[i+1]-b[i];
		for(int j=i-1;j>=1;j--){
			if(tm>=(suo[i]-suo[j])*(b[j+1]-b[j])){
				tm-=(suo[i]-suo[j])*(b[j+1]-b[j]);
				cnt+=b[j+1]-b[j];
			}else{
				cnt+=tm/(suo[i]-suo[j]);
				break;
			}
		}
		ans=max(cnt,ans);
		tm=m;
		cnt=b[i+1]-b[i];
		for(int j=i+1;j<=l;j++){
			if(tm>=(suo[j]-suo[i])*(b[j+1]-b[j])){
				tm-=(suo[j]-suo[i])*(b[j+1]-b[j]);
				cnt+=b[j+1]-b[j];
			}else{
				cnt+=tm/(suo[j]-suo[i]);
				break;
			}
		}
		tm=m;
		ans=max(cnt,ans);
		cnt=b[i+1]-b[i];
	}
	cout<<ans;
	return 0;
} 