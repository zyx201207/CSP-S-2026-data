#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,ans=1;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	sort(a+1,a+1+n);
	long long t=1e9,idx=1;
	for(int i=1;i<=n;i++){
		if(t>abs(a[i]-sum)){
			t=abs(a[i]-sum);
			idx=i;
		}
	}
	long long l=idx-1,r=idx+1;
	bool ll=0,rr=0,f=0;
	while(m>0){
		if(ll==1&&rr==1){
			f=1;
			cout<<ans-1;
			break;
		}else{
			if(ll==0&&rr==1){
				if(abs(a[idx]-a[l])<=m){
					ans++;
					m-=abs(a[idx]-a[l]);
					l--;
					if(l==0){
						ll=1;
					}
				}else{
					m=0;
				}
			}else if(rr==0&&ll==1){
				if(abs(a[r]-a[idx])<=m){
					ans++;
					m-=abs(a[r]-a[idx]);
					r++;
					if(r==n+1){
						rr=1;
					}
				}else{
					m=0;
				}
			}else if(rr==0&&ll==0){
				if(abs(a[idx]-a[l])<abs(a[r]-a[idx])){
					if(abs(a[idx]-a[l])<=m){
						ans++;
						m-=abs(a[idx]-a[l]);
						l--;
						if(l==0){
							ll=1;
						}
					}else{
						m=0;
					}
				}else{
					if(abs(a[r]-a[idx])<=m){
						ans++;
						m-=abs(a[r]-a[idx]);
						r++;
						if(r==n+1){
							rr=1;
						}
					}else{
						m=0;
					}
				}
			}
		}
	}
	if(f==0){
		cout<<ans;
	}
	return 0;
} /*
    S  S S 
    \ | /
   (¶þ¶þ) 
   ¡¿ ¡¾  
*/
