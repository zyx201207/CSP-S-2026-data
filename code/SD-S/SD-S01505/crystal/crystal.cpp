#include<bits/stdc++.h> 
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c_min=0x3f3f3f3f,l,r;
	cin>>n>>m;
	int a[n+5],c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c_min>c[i]){
			c_min=c[i];
			l=i;r=i;
		}
	}
	int l_spd=c[l];
	int r_spd=c[r+1]*(r-l+1);
	while(m>0){
		l_spd=c[l];
		r_spd=c[r+1]*(r-l+1);
		if(l==1&&r==n) break;
		else if(l!=1&&r==n){
			if(m-l_spd>0){
				a[l-1]=a[l];
				c[l-1]=a[l-1]-a[l-2];
				l--;
				m-=l_spd;
			}else if(m-l_spd==0){
				l--;
				break;
			}else{
				break;
			}
		}else if(l==1&&r!=n){
			if(m-r_spd>0){
				for(int i=l;l<=r;i++){
					a[i]=a[r+1];
				}
				r++;
				m-=r_spd;
			}else if(m-r_spd==0){
				r++;
				break;
			}else{
				break;
			}
		}else if(l!=1&&r!=n){
			if(l_spd<=r_spd){
				if(m-l_spd>0){
					a[l-1]=a[l];
					c[l-1]=a[l-1]-a[l-2];
					l--;
					m-=l_spd;
				}else if(m-l_spd==0){
					l--;
					break;
				}else{
					break;
				}
			}else if(l_spd>=r_spd){
				if(m-r_spd>0){
					for(int i=l;l<=r;i++){
						a[i]=a[r+1];
					}
					r++;
					m-=r_spd;
				}else if(m-r_spd==0){
					r++;
					break;
				}else{
					break;
				}
			}
		}
	}
	cout<<r-l+1;
	return 0;
}
