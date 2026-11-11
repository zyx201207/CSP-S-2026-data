#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,x;
int a[N],b[N],f1,f2;
int mi=INT_MAX,ma=INT_MIN,maa=INT_MIN;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
		
	}
	for(int i=0;i<n;i++){
		if(!(a[i]==i+1)){
			f1=1;
		}
		if(i==1){
			x=a[i]-a[i-1];
		}
		//cout<<x<<"...";
		if(!(i!=0&&x==a[i]-a[i-1])){
			f2=1;
		//	cout<<a[i]-a[i-1]<<'=';
			}
	}
	if(f1==0||f2==0){
		int mid=mi+(ma-mi)/2;
		for(int i=0;i<n;i++){
			b[i]=abs(a[i]-mid);
		}
		sort(b,b+n);
		int s=0,cnt=0;
		while(cnt<n){
			s+=b[cnt];
			if(s<=m)
			{
				cnt++;
				//cout<<b[cnt]<<" ";
			}else{
				break;
			}
		}
		//cout<<'.';
		cout<<cnt;
		return 0;
	}
	for(int i=mi;i<=ma;i++){
		for(int j=0;j<n;j++){
			b[j]=abs(a[j]-i);
		}
		sort(b,b+n);
		int s=0;
		int cnt=0;
		while(cnt<n){
			s+=b[cnt];
			if(s<=m)
			{
				cnt++;
				//cout<<b[cnt]<<" ";
			}else{
				break;
			}
		}
		maa=max(maa,cnt);
	}
	cout<<maa;
	return 0;

}
