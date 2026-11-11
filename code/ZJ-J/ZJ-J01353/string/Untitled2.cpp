#include<bits/stdc++.h>
using namespace std;
unsigned long long sum,q,ans,s;
long long n,l,r,p,a[208888],d[208888];
char c[208888];
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i-1];
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	l=1;
	r=n;
	q=sum;
	while(q>=n/2){
		if(q-a[l]<d[r]){
		    s=0;
			while(q-a[l]<d[r]){
				s+=d[r];
				if(r<sum/2) break;
				r--;
			}
			p=a[l]-s-q;
			ans+=s+p;
			q=q-s-p;
		}
		else {
			if(c[l]!=c[r]){
			   ans+=a[l];
		    }
		    q=q-a[l];
		}
		if()l++;
	}
	cout<<ans;
	return 0;
}
/*
3
3 a
1 b 
1 c
*/
