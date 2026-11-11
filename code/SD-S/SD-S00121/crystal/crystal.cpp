#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans=1,b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=a[2]-a[1],flag=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=l){
			flag=0;
			break;
		}
	}
	if(flag==1){
		int l2=l;
		while(m!=0){
			if(m-l2>=0){
				m=m-l2;
				ans+=1;
				l2+=l; 
			}
			else m=0;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0,x=m;
		for(int j=1;j<=i;j++){
			b[j]=abs(a[j]-a[i]);
		}
		sort(b+1,b+i+1);
		for(int j=1;j<=i;j++){
			if(x-b[j]>=0)x=x-b[j],sum+=1;
			else continue;
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
