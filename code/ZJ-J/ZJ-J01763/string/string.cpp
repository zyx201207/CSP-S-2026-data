#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c[200010];
int n,a[200010];
ll le,k,mi,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		le+=a[i];
	}
	ll p=(le+1)/2;
	while(k<p){
		mi++;
		k+=a[mi];
	}
	int l,r,x=k-p,y=p-(k-a[mi])-(le&1);
	if(x>y){
		l=mi-1;
		r=mi;
		a[mi]=x-y;
	}
	else if(y>x){
		l=mi;
		r=mi+1;
		a[mi]=y-x;
	}
	else{
		l=mi-1;
		r=mi+1;
	}
	while(l>0&&r<=n){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l--;
			}
			else if(a[r]<a[l]){
				a[l]-=a[r];
				r++;
			}
			else{
				l--;
				r++;
			}
		}
		else{
			if(a[l]<a[r]){
				s+=a[l];
				a[r]-=a[l];
				l--;
			}
			else if(a[r]<a[l]){
				s+=a[r];
				a[l]-=a[r];
				r++;
			}
			else{
				s+=a[l];
				l--;
				r++;
			}
		}
	}
	cout<<s;
	return 0;
}