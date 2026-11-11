#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,c=0,rl=1,rr=1,mc=0,len=1;
	while(r<=n&&l<=r){
		if(c>m){			
			c-=(a[r-1]-a[l]);
			l++;
			len--;
		}else if(c<m){
			r++;
			c+=(a[r]-a[r-1])*(r-l);
			len++;
		}else{
    		if(len>mc){
				mc=len;
				rl=l; rr=r;
			}
			c-=(a[r-1]-a[l]);
			r++;
			c+=(a[r]-a[r-1])*(r-l);
			l++;
		}

	}

	int p=upper_bound(a+1,a+n+1,a[rr])-lower_bound(a+1,a+n+1,a[rr]);
	cout<<p+mc-1<<endl;
	return 0;
}
