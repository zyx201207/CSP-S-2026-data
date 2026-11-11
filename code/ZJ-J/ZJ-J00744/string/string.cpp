#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,a[N],sum,ans;
char c[N];
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
//		for(int j=1;j<=a[i];++j) s+=c[i];
	}
//	s2=s;
//	reverse(s.begin(),s.end());
//	long long cnt=0;
//	for(int i=0;i<int(s.size());++i) if(s[i]!=s2[i]) ++cnt;
//	cout<<cnt/2;
	long long l1=0,l2=0,yl1=0,yl2=0,ans=0,wz=1,wz1=1;
	for(int i=1,j=n;i<=j&&i<=n&&j>=1;++i){
		if(wz1) l1+=a[i];
		else{
			l1=yl1+a[--i];
			wz1=1;
		}
		if(wz) l2+=a[j];
		else{
			l2=yl2+a[++j];
			wz=1;
		}
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		while(l2<l1&&j>i){
			--j;
			if(c[i]!=c[j]){
				ans+=min(l1,l2+a[j])-l2;
				if(l2+a[j]>l1){
					wz=0;
					yl2=l2;
					a[j]-=min(l1,l2+a[j])-l2;
				}
			}
			l2+=min(l1,l2+a[j])-l2;
		}
		while(l1<l2&&i<j){
			++i;
			if(c[i]!=c[j]){
				ans+=min(l1+a[i],l2)-l1;
				if(l1+a[i]>l2){
					wz1=0;
					yl1=l1;
					a[i]-=min(l2,l1+a[i])-l1;
				}
			}
			l1+=min(l2,l1+a[i])-l1;
		}
		--j;
	}
	cout<<ans;
	return 0;
}
