#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,p,k;
ll a[300000];
bool f=1;

bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	for(ll i=1;i<=10;i++){
		if(i!=pow(2,i)-1)	f=0;
	}
	sort(a+1,a+n+1,cmp);
	p=a[1];
	if(f==1){
		for(ll i=1;i<=m;i++){
			p=p&a[i];
		}
		cout<<p;
		return 0;
	}
	else{
		for(ll i=1;i<=n;i++){
			p=a[i];
			for(ll j=i;j<=m;j++){
				if(p&a[j]==0)	break;
				else p=p&a[j];

			}
			if(p)	break;

		}
	}
	cout<<p<<endl;
	return 0;
} 
