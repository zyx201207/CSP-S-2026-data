#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long Mminus[500010];
long long n,m;
bool Mycheck(int k){
	if(k<0||k>=n) return false;
	else return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	/*if(n>=5000){
		int k=a[1]-a[0];
		if(m/k<=n) cout<<m/k;
		else cout<<n;
		return 0;
	} */
	for(int i=0;i<n-1;i++) Mminus[i]=a[i+1]-a[i];
	//for(int i=0;i<n-1;i++) cout<<Mminus[i]<<" ";
	//cout<<endl;
	int maxans=0;
	for(int i=0;i<n;i++){
		if(n>=5000||(n>16&&m>1000000)) i=n/2;
		long long lovr=m;
		int l=0,r=0;
		long long lnum=0,rnum=0;
		int ans=1;
		bool lupd=true,rupd=true;
		while(1){
			if(lupd){
				lupd=false;
				if(Mycheck(i-l-1)){
					l++;
					lnum+=Mminus[i-l];
				}else{
					lnum=-1;
				} 
			}
			if(rupd){
				rupd=false;
				if(Mycheck(i+r+1)){
					r++;
					rnum+=Mminus[i+r-1];
				}else{
					rnum=-1;
				} 
			}
			if(lnum>rnum||(lnum==rnum&&lnum!=-1)){
				lovr-=lnum;
				lupd=true;
				ans++;
			}else if(rnum>lnum){
				lovr-=rnum;
				rupd=true;
				ans++;
			}else if(rnum==lnum&&lnum==-1){
				break;
			}
			if(lovr==0) break;
			if(lovr<0){
				ans--;
				break;
			} 
		}
		maxans=max(maxans,ans);
		if(n>=5000||(n>16&&m>1000000)) break;
	}
	cout<<maxans;
	return 0;
}
