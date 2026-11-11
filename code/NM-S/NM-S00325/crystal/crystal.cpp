#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b,c;
	int cnt=0;
	int a1,b1,c1;
	int a[500005];

	if(n%2!=0){
		for(int i=1;i<=n;i++){
			c=(i+1)/2;
			c++;
			b=(i+1)/2;
			b--;
			cin>>a[i];
			int w=(i+1)/2;
			a1=a[w];
			b1=a[b];
			c1=a[c];
			if(m>a1-b1&&m>c1-a1){
				if(a1-b1<c1-a1){
				m=m-(a1-b1);
			}
			if(a1-b1>=c1-a1){
				m=m-(c1-a1);
			}
			cnt++;
			
			}
			if(m<a1-b1&&m<c1-a1){
				continue;
			}
		}
		cout<<cnt-1;
	}
	if(n%2==0){
		for(int i=1;i<=n;i++){
			c=i/2;
			c++;
			b=i/2;
			b--;
			cin>>a[i];
			int w=i/2;
			a1=a[w];
			b1=a[b];
			c1=a[c];
			if(m>a1-b1&&m>c1-a1){
				if(a1-b1<c1-a1){
					m=m-(a1-b1);
				}
				if(a1-b1>=c1-a1){
					m=m-(c1-a1);
				}
				cnt++;
			}
			if(m<a1-b1&&m<c1-a1){
				continue;
			}
		}
		cout<<cnt;
	}
	
	return 0;
} 
