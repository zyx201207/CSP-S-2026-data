#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0},b[500005]={0},c[500005]={0};
long long ans=0,l,r,d,rnum=0,lnum=0,m,t=0,Ans=0,x;
long long n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	x=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(i==2){
			d=b[i];
			r=i;
		}
		else{
			if(d>b[i]){
				d=b[i];
				r=i;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(b[i]==d){
			t++;
			c[t]=i;
		}
	}
	if(t==n-1){
		for(int i=1;i<=n-1;i++){
			if((1ll*c[1]*i*i)<=1ll*2*m){
				Ans=i;
			}
		}
	}
		else{
			Ans=0;
		for(int i=1;i<=t;i++){
			m=x;
			r=c[i];
			l=r;
			ans=1;
			lnum=0;
			rnum=0;
			while(m>0&&r-l<n-1){
				if(l==1){
					r++;
					rnum=1ll*ans*b[r];
					m=m-rnum;
					ans++;
				}
				else{
					if(r==n){
						lnum=lnum+b[l];
						m=m-lnum;
						l--;
						ans++;
					}
					else{
						if(1ll*ans*b[r+1]<lnum+b[l]){
							r++;
							rnum=1ll*ans*b[r];
							lnum=lnum+b[r];
							m=m-rnum;
							ans++;
						}
						else{
							lnum=lnum+b[l];
							m=m-lnum;
							l--;
							ans++;
						}
					}
				}
			}
			if(m<0){
				ans--;
			}
				if(ans>Ans){
					Ans=ans;
				}

		}
	}
	
	cout<<Ans;
	return 0;
}
