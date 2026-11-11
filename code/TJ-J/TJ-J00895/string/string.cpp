#include<bits/stdc++.h>
using namespace std;
int n,a;
long long len,a[200005],p[200005],ans=0;
char c[200005];
int main(){
	freopen("string.in","r"stdin);
	freopen("string.out","w"stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		p[i]=p[i-1]+a[i];
		len+=a[i];	
	}
	len=len/2;
	bool st=0;
	for(int i=1;i<=n;i++){
		if(p]i<=len&&st==0){
			x.d=a[i]
			x.b=c[i];
			s.push(x);
		}
		else{
			if(p[i+1]>1&&st==0) continue;
			x=s.top();
			s.pop();
			long long l=p[i]+1-x.d,r=p[i];
			if(x.b!=c[i]){
				if(a[i]<=x.d){
					ans+=a[i];
					a[i+1]==(x.d-a[i]);
					if(c[i+1]!=x.b)
						ans+=a[i]-x.d;
					
				}
				else{
					x=s.top();
					if(x2.b!=c[i])
					ans+=(a[i]-x.d);
				}
			}
				
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
