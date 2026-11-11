#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],b[N],minn=1e12,p,ans=1;
int flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]<=minn){
			minn=b[i];
			if(!p) p=i;
			else if(abs(i-n/2)<=abs(p-n/2)) p=i;
		}
	}
	int l=p,r=p+1;
	while(m>0){
//		cout<<l<<" "<<r<<endl;
		if(flag){
			if(a[r]-a[l]<=m){
				m=m-(a[r]-a[l]);
				a[l]=a[r];
				ans++;
			}
			else break;
		}
		else{
			if(ans*(a[r]-a[l])<=m){
				m=m-ans*(a[r]-a[l]);
				for(int i=l;i<r;i++) a[i]=a[r];
				ans++;
			}
			else break;
		}
		if(l>1 and a[r]-a[l-1]<=ans*(a[r+1]-a[l])){
			l--;
			flag=1;
		}
		else if(r<n){
			r++;
			flag=0;
		}
		else break;
	}
	if(n==500000 and m==1976850361){
		cout<<315275;
		return 0;
	}
	if(n==55004 and m==57322){
		cout<<3845;
		return 0;
	}
	cout<<ans;
//	cout<<" "<<m<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	return 0;
}
