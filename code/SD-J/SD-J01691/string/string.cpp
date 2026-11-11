#include <bits/stdc++.h>
using namespace std;
struct abs{
	int x;
	string y;
}b[200011],c[200011];
int n;
int a[200010];
char t[200010];
long long cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	int maxx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
		maxx=max(a[i],maxx);
	}
	if(maxx<1000000000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=t[i];
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]!=s[n+1-i]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
		cnt+=a[i];
	}
	cnt/=2;
	long long sum=0;
	int num=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];		
		if(sum>=cnt){
			a[i]=cnt-sum+a[i];
			num++;
			b[num].x=a[i];
			b[num].y=t[i];
			break;
		}	

		num++;
		b[num].x=a[i];
		b[num].y=t[i];

	}
	int numm=0;
	sum=0;
	for(int i=n;i>=1;i--){	
		sum+=a[i];	
		if(sum>=cnt){
			a[i]=cnt-sum+a[i];
			numm++;
			c[numm].x=a[i];
			c[numm].y=t[i];
			break;
		}	

		numm++;
		c[numm].x=a[i];
		c[numm].y=t[i];

	}
	int l=0,r=0,d=0;
	int is=-1;
	while(l<=num&&r<=numm){
		if(d==0) {
			l++;
			r++;
			if(b[l].x==c[r].x){
				if(c[r].y!=b[l].y) ans+=c[r].x;			
				continue;
			} 
			if(b[l].x>c[r].x){
				if(c[r].y!=b[l].y) ans+=c[r].x;
				r++;
				d=b[l].x-c[r].x; 
				is=1;
			} 
			if(b[l].x<c[r].x){
				if(c[r].y!=b[l].y) ans+=b[l].x;
				l++;
				d=c[r].x-b[l].x;
				is=0;
			}
		}
			if(is==1){
				if(c[r].x<d) {
					if(c[r].y!=b[l].y) ans+=c[r].x;
					d-=c[r].x;
					r++;
					continue;
				}
				if(c[r].x>d){
					if(c[r].y!=b[l].y) ans+=d;
					d=c[r].x-d;					
					l++;
					is=0;
					continue;
				}
				if(c[r].x==d){
					if(c[r].y!=b[l].y) ans+=d;
					d=0;
					continue;			
				}
			}
			if(is==0){
				if(b[l].x<d) {
					if(c[r].y!=b[l].y) ans+=b[l].x;
					d-=b[l].x;
					l++;
					continue;
				}
				if(b[l].x>d){
					if(c[r].y!=b[l].y) ans+=d;
					d=b[l].x-d;	
					r++;
					is=1;
					continue;
				}
				if(b[l].x==d){
					if(c[r].y!=b[l].y) ans+=d;
					d=0;
					continue;
				}
			}
	}
	cout<<ans<<endl;
	}

	return 0;
} 
