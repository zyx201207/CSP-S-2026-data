#include<bits/stdc++.h>
using namespace std;
unsigned long long sum,q,ans;
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
	while(l<r){
		if(q-a[l]<d[r]){
			while(1){
				if(a[l]-(q-d[r]+1)>=0){
					a[l]=a[l]-(q-d[r]+1);
					if(c[r]!=c[l]){
						ans+=(q-d[r]+1);
					}
					q=d[r]-1;
					r--;
				}
				else break;
			}
			if(a[l]<0){
				q=q-a[l]+1;
				r--;
				if(c[l]!=c[r]){
					ans+=a[l];
				}
			}
		}
		else {
			if(c[l]!=c[r]){
			   ans+=a[l];
		    }
		    q=q-a[l];
		}
		l++;
	}
	cout<<ans;
	return 0;
}
/*
3
3 a
1 b 
1 c

3

2 a

2 b

1 c

*/
