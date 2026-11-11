#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,sum=0,s2=0,mid=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==0) sum=sum/2;
	else sum=sum/2+1;
	
	for(int i=1;i<=n;i++){
		s2+=a[i];
		if(s2>=sum){
			mid=i;
			break;
		}
	}
	int l=1,r=n;
	int k1=a[l],k2=a[r],s=0;
	char lc=c[l],rc=c[r];
	//cout<<mid<<endl<<endl;
	while(1){
		if(l==mid){
			while(mid<r){
				if(lc!=rc) ans+=k2;
				rc=c[--r];
				k2=a[r];
			}
			//cout<<111<<endl; 
			//int p=s+a[mid]-sum-(sum-s);
			//ans+=p;
			//if(lc!=rc) ans+=p;
			break;
		}else if(r==mid){
			while(mid>l){
				if(lc!=rc) ans+=k1;
				lc=c[++l];
				k1=a[l];
			}
			//cout<<111<<endl; 
			//int p=s+a[mid]-sum-(sum-s);
			//ans+=p;
			//if(lc!=rc) ans+=p;
			break;
		}
		if(lc!=rc) ans+=min(k1,k2);
		if(k1>k2){
			k1=k1-k2;
			s+=k2;
			k2=a[--r];
			rc=c[r];
		}else if(k1<k2){
			k2=k2-k1;
			s+=k1;
			k1=a[++l];
			lc=c[l];
		}else{
			k1=a[++l];
			k2=a[--r];
			s+=k1;
			lc=c[l];
			rc=c[r];
		}
		//cout<<l<<" "<<r<<endl;
		//cout<<k1<<" "<<k2<<" "<<s<<endl;
		//cout<<lc<<" "<<rc<<endl;
		//cout<<ans<<endl<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
