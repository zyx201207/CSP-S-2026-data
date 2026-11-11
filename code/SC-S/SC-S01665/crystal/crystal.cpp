#include<bits/stdc++.h>
using namespace std;
int n;
bool f1,f2;
long long m,a[500005],k,op;
void h(long long u,long long q,int ir,int l,int r,long long p){
	k=max(k,p);
	if(q-abs(u-a[ir-l-1])<0&&q-abs(u-a[ir+r+1])<0)return;
	if(ir-l>1&&ir+r<n){
		if(abs(u-a[ir-l-1])<abs(u-a[ir+r+1])){
			h(u,q-abs(u-a[ir-l-1]),ir,l+1,r,p+1);
		}
		else{
			h(u,q-abs(u-a[ir+r+1]),ir,l,r+1,p+1);
		}
		return;
	}
	if(ir-l==1&&q-abs(u-a[ir+r+1])>=0){
		h(u,q-abs(u-a[ir+r+1]),ir,l,r+1,p+1);
		return;
	}
	if(ir+r==n&&q-abs(u-a[ir-l-1])>=0){
		h(u,q-abs(u-a[ir-l-1]),ir,l+1,r,p+1);
		return;
	}
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1];
		return 0;
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f1=1;
		}
		if(a[i]-a[i-1]!=a[i+1]-a[i]&&i!=n&&i!=1){
			f2=1;
		}
	}
	if(!f1){
		long long o=1,t=1;
		while(m>=o){
			if(t>=n)break;
			m-=o;
			if(t%2==0){
				o++;
			}
			t++;
		}
		if(t>n)t=n;
		cout<<t;
		return 0;
	}
	if(!f2){
		long long o=1,t=1,u=a[n]-a[n-1];
		while(m>=o*u){
			if(t>=n)break;
			m-=o*u;
			if(t%2==0){
				o++;
			}
			t++;
		}
		if(t>n)t=n;
		cout<<t;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		h(a[i],m,i,0,0,1);
		if(op>k){
			cout<<op;
			return 0;
		}
		op=k;
		k=0;
	}
	cout<<op;
    return 0;
}