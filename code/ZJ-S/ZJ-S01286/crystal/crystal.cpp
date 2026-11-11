#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long n,m,c,d1,e1=0,d2,e2=0,i,f,j,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long h=0;h<n;h++){
		cin>>a[h];
	}
	sort(a,a+n);
	c=a[1]-a[0];
	for(long long h=1;h<n-1;h++){
		b[h]=a[h+1]-a[h];
		if(b[h]<c&&b[h]!=0){
			d1=h;
			e1=0;
			c=b[h];
		}
		else if(b[h]==0&&a[h]!=a[d2]&&a[h]!=a[d1]){
			d2=h;
			e2=0;
		}
		if(a[h]-a[d1]==0){
			e1++;
		}
		else if(a[h]-a[d2]==0){
			e2++;
		}
		if(e2>=e1){
			e1=e2;
			e2=1;
			d1=d2;
			d2=0;
		}
	}
	if(a[n-1]==a[d1]){
		e1++;
	}
	if(d1+e1==n){
		i=d1-1;
		while(m>0&&i>=0){
			m=m-a[d1]+a[i];
			i--;
			if(m>=0){
				e1++;
			}
		}
		cout<<e1;
		return 0;
	}
	else if(d1+e1==1){
		i=0;
		while(m>0&&i<n){
			m-=b[i]*e1;
			i++;
			if(m>=0){
				e1++;
			}
		}
		cout<<e1;
		return 0;
	}
	else{
		f=d1-1;
		j=d1+e1-1;
		while(m>0&&f>=0&&j<n){
			if(b[f]<b[j]*e1){
				m=m-b[f];
				if(m>=0){
					e1++;
				}
				f--;
			}
			else{
				m-=b[j]*e1;
				for(long long h=0;h<f;h++){
					b[h]=a[j]-a[h];
				}
				if(m>=0){
					e1++;
				}
				j++;
			}
		}
		cout<<e1;
	}
	return 0;
}




