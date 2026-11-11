#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int MAXN=5e5+10;
const long long minn=-1*1e12;
long long n,m;
long long a[MAXN];
long long ans=minn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n;i++){
		long long use=0;
		long long num=0;
  		long long l=1,r=n;
  		while(l<=r && use<=m){
			if(abs(a[l]-a[i])>abs(a[r]-a[i])){
				num++;
				use+=abs(a[r]-a[i]);
				r--;
			}else{
				num++;
				use+=abs(a[l]-a[i]);
				l++;
			}
		}
  		ans=max(ans,num);
	}
	cout<<ans-1;
	return 0;
}

