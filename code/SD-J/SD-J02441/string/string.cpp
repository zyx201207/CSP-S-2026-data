#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct stud{
	int x;
	char y;
}a[N];
stud b[N],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,st=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].x);
		scanf("%c");
		scanf("%c",&a[i].y);
		st+=a[i].x;
	}
	if(st%2==1){
		int mid=(st+1)/2,mix,sum=0,s;
		for(int i=1;i<=n;i++){
			sum+=a[i].x;
			if(sum>=mid){
				mix=i;
				s=sum-mid;
				break;
			}
		}
//		cout<<mix<<endl<<endl;
		b[1].x=s,b[1].y=a[mix].y;
		for(int i=2;i<=n-mix+1;i++){
			b[i].x=a[i+mix-1].x;
			b[i].y=a[i+mix-1].y;
		}
		c[1].x=a[mix].x-s-1;
		c[1].y=a[mix].y;
		for(int i=2;i<=mix;i++){
			c[i].x=a[mix-i+1].x;
			c[i].y=a[mix-i+1].y;
		}
		int p=1,q=1,ans=0;
		while(1){
			if(p>n-mix+1||q>mix){
				break;
			}
			while(b[p].x==0){
				p++;
			}
			while(c[q].y==0){
				q++;
			}
			if(b[p].y!=c[q].y){
				if(b[p].x>c[q].x){
					ans+=c[q].x;
					b[p].x-=c[q].x;
					q++;
				}
				else if(b[p].x<c[q].x){
					ans+=b[p].x;
					c[q].x-=b[p].x;
					p++;
				}
				else{
					ans+=b[p].x;
					p++;
					q++;
				}
			}
			else{
				if(b[p].x>c[q].x){
					b[p].x-=c[q].x;
					q++;
				}
				else if(b[p].x==c[q].x){
					p++,q++;
				}
				else{
					c[q].x-=b[p].x;
					p++;
				}
			}
		}	
		cout<<ans;
	}
	else {
		int mid=(st)/2,mix,s,sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i].x;
			if(sum>=mid){
				mix=i;
				s=sum-mid;
				break;
			}
		}
		b[1].x=s,b[1].y=a[mix].y;
		for(int i=2;i<=n-mix+1;i++){
			b[i].x=a[i+mix-1].x;
			b[i].y=a[i+mix-1].y;
		}
		c[1].x=a[mix].x-s;
		c[1].y=a[mix].y;
		for(int i=2;i<=mix;i++){
			c[i].x=a[mix-i+1].x;
			c[i].y=a[mix-i+1].y;
		}
		int p=1,q=1,ans=0;
		while(1){
			if(p>n-mix+1||q>mix){
				break;
			}
			while(b[p].x==0){
				p++;
			}
			while(c[q].y==0){
				q++;
			}
			if(b[p].y!=c[q].y){
				if(b[p].x>c[q].x){
					ans+=c[q].x;
					b[p].x-=c[q].x;
					q++;
				}
				else if(b[p].x<c[q].x){
					ans+=b[p].x;
					c[q].x-=b[p].x;
					p++;
				}
				else{
					ans+=b[p].x;
					p++;
					q++;
				}
			}
			else{
				if(b[p].x>c[q].x){
					b[p].x-=c[q].x;
					q++;
				}
				else if(b[p].x==c[q].x){
					p++,q++;
				}
				else{
					c[q].x-=b[p].x;
					p++;
				}
			}
		}	
		cout<<ans;
	}
	return 0;
} 
































