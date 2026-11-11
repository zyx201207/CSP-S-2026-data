#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define time cerr<<"\nTime is:"<<clock()
ll n,m;
ll a[200005];
bool cmp(ll x,ll y){
	return x>y;
}
ll maxx=0;
int main(){
	fin("and1.in");
	//fout("and.out");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			ll sum=a[i],cnt=0,t=2;
			int j=m;
			for(int k=i+1;k<=n;k++){
				cnt=sum&a[k];
				j--;
				if(j==0){
					maxx=max(maxx,cnt);
					if(k!=n){
						j++;
					}
					if(k==n&&i+t+m-2<=n){
						k=i+t,t++,j=m-1;
						sum=a[i],cnt=0;
					}
				}
				else sum=cnt;
			}
		}
		cout<<maxx;
	}
	else{
		if(m==1){
			
			cout<<a[1];
		}	
		else if(m==2) {
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int t1=a[i],t2=a[j];
					if(maxx<=(t1&t2)){
						maxx=(t1&t2);
					}
				}
			}
			cout<<maxx;
		}
		else if(m==n){
			ll cnt=a[1];
			for(int i=2;i<=n;i++){
				cnt=cnt&a[i];
			}
			cout<<cnt;
		}
		else if(m==n-1){
			ll cnt=a[1];
			for(int i=1;i<=n;i++){
				for(int j=2;j<=n;j++){
					if(j!=i) cnt=cnt&a[i];
				}
				maxx=max(maxx,cnt);
			}
			cout<<maxx;
		}
	}
	return time,0;
}//F
