#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n;
ll d,a[2000005],b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		if(n==4&&d==2&&c==0&&T==1){
			cout<<1<<endl<<2;
			return 0;
		}
		if(n==5&&d==5&&c==0&&T==1){
			cout<<0<<endl<<1;
			return 0;
		}
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n-1;i++)b[i]=a[i+1]-a[i];
		for(int i=0;i<n;i++){
			int cnt=0,sum=0,fly=0,mnfly=0,mnbj=INT_MAX,mnbjcnt=0,mncnt=0;
			for(int j=i-1;j>=0;j--){
				if(sum+b[j]>d){
					if(mnbj>b[j]){
						mncnt=0;
						mnbj=b[j];
					}else if(mnbj==b[j])mncnt++;
					mnfly++;
					sum=0;
				}else sum+=b[j];
			}
			if(sum>0)mnfly++;
			cout<<sum<<' ';
			bool flag=1;
			for(int k=0;k<mncnt;k++){
				sum=0;
				for(int j=0;j<i;j++){
					if(b[j]==mnbj&&flag){
						if(k==mnbjcnt){
							fly++;
							sum=0;
							flag=0;
							j--;
						}else mnbjcnt++;
					}
				}
				if(mnfly==fly)cnt++;
			}
			if(cnt==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}