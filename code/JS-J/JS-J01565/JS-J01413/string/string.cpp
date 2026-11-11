#include<bits/stdc++.h>
using namespace std;
struct note{
	int a;
	char c;
};
note b[266666];
long long x[266666],y[266666];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ma=0;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		ma+=b[i].a;
	}
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]+b[i].a;
	}
	for(int i=n;i>=1;i--){
		y[i]=y[i+1]+b[i].a;
	}
	int l=0,r=n;
	long long le=0,ri=0;
	long long c=0,d=0;
	long long ans=0;
	while(1){
		if(l>r)break;
		long long a1=x[l+1]-le,a2=y[r-1]-ri;
		if(a1<a2){
			if(r!=n)if(b[l+1].c!=b[r].c)ans+=a1-d;
			if(b[l+1].c!=b[r-1].c)ans+=a2-a1;
			r--;
			le=a1;
		}
		else{
			if(l!=0)if(b[l].c!=b[r-1].c)ans+=a2-c;
			if(b[l+1].c!=b[r-1].c)ans+=a1-a2;
			l++;
			ri=a2;
		}
		c=a1,d=a2;
	}cout<<ans;
	return 0;
}
