#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
long long m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i==1)b[0]++;
		else b[a[i]-a[i-1]]++;
	}
	if(b[0]==n){
	cout<<n;
	return 0; 
	}
	if(b[a[2]-a[1]]==n){
		for(int i=1;i<=n;++i){
			if(b[i]*(i-1)<=m)cnt=i;
			else {
				cout<<cnt;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	int l=1,r=n,mid=(l+r)/2;
	while(l<r){
	//	cout<<mid<<endl;
		bool fl=0;
		for(int i=mid;i<=n;++i){
			long long m1=m;
			for(int j=i-mid+1;j<mid;++j){
				if(a[i]>0){
					if(a[j]>=0)m1-=a[i]-a[j];
					else m1-=a[i]+abs(a[j]);
				}
				else{
					m1-=abs(a[j])-abs(a[i]);
				}
				if(m1<0)break;
			}
			if(m1>=0){
			//	cout<<m1<<endl;
				cnt=mid;
				l=mid+1;
				mid=(l+r)/2;
				fl=1;
				break;
			}
		}
		if(fl==0)
		{
			r=mid-1;
			mid=(l+r)/2;
		}
	}
	cout<<cnt;
	return 0;
} 
