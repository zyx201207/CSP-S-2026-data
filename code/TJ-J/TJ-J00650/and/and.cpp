#include<bits/stdc++.h>
using namespace std;
#define N 2000005
long long n,m,a[N],aa[N],maxx,down=2,cnt,ans;
bool flag = false,f=false;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[i]=a[i];
	}
	while(cnt>m){
	for(int i=1;i<=n;i++){
		a[i]-=down;
		if(a[i]<=0){
			a[i]==0;
			cnt--;
			if(cnt<=m){
				flag=true;
			}
		}
		if(flag)break;
	}
	if(flag)break;
	down*=2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0&&!f){
			ans=aa[i];
			f=true;
		}else if(a[i]>0){
			ans&=aa[i];
		}
	}
	cout<<ans;
}
