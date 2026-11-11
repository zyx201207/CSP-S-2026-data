#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[200010],l[200010]={0},lq[200010]={0};
long long ans[200010]={0};
int main(){
	cin>>c>>t;
	long long ct=0;
	while(t--){
		cin>>n>>d;
		long long fl=(1+d)*d>>1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cnt=0;
		for(int i=1;i<n;i++){
			l[i]=a[i+1]-a[i];
			if(l[i]>d){
				l[i]=0;
				break;
			}
			lq[i]=l[i]+lq[i+1];
			cnt++;
		}
		long long road=0,fr=0;
		for(int i=1;i<=cnt;i++){
			if(l[i]<=d)road++;
			if(lq[i]<=d)fr++;
		}
		ans[ct]=(road+fr)>>d;
		if(fr+1==n&&d>=3)ans[ct]=0;
		ct++;
		
	}
	for(int i=0;i<ct;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
