#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=-0x3f3f3f3f3f3f3f3f;
void sub_1(){
	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=0,m2=m;
		for(int j=i;j>=1;j--){
			if(m2>=a[i]-a[j]){
				m2-=a[i]-a[j];
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return;
}
void sub_2(){
	int cha=a[2]-a[1];
	int l=0,r=n,mid=l+r>>1;
	while(l+1<r){
		if((mid-1)*mid*cha/2<=m){
			l=mid+1;
		}else r=mid;
		mid=l+r+1>>1;
		cout<<l<<' '<<mid<<' '<<r<<' '<<(mid-1)*mid*cha/2<<endl;
	}
	cout<<l;
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000) 
	sub_1();
	else sub_2();
	return 0;
}
/*
5 8
2 4 6 8 10
*/
