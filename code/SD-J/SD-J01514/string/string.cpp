#include<bits/stdc++.h>
using namespace std;
struct xx{
	char s;
	long long m;
	long long x,y;
}a[200005];
long long n,mid=1,l,r,l1,r1,sum;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	l1=1,r1=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
		a[i].x=mid,a[i].y=mid+a[i].m-1;
		mid=a[i].y+1;
	}
	mid--;
	l=1,r=mid,mid/=2;
	while(l<=mid&&r>=mid&&l<r&&l1<r1){
		if(a[l1].s==a[r1].s){
			if(l1==r1) break;
			if(a[l1].m<=a[r1].m){
				l=a[l1].y+1,r=r-a[l1].m,a[r1].m-=a[l1].m;
			}
			else{
				l+=a[r1].m,a[l1].m-=a[r1].m,r=a[r1].x-1; 
			}
			if(l==a[l1].y+1) l1++;
			if(r==a[r1].x-1) r1--; 
		}
		else{
			long long t=min(a[l1].m,a[r1].m);
			sum+=t;
			l+=t,r=r-t;
			a[l1].m-=t,a[r1].m-=t;
			if(l==a[l1].y+1) l1++;
			if(r==a[r1].x-1) r1--;
		}
	}
	cout<<sum;
	return 0;
}
