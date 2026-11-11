#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
long long n,m,a[500005],ans,b[500005];
long long check(long long k){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<k){
			cnt+=k-a[i];
		}
	}
	return cnt;
}
long long find(int w){
	//cout<<"w:"<<w<<endl;
	long long z=0,x=0,q=0;
	for(int i=1;i<=n;i++){
		if(a[i]<w)b[++x]=w-a[i];
		else if(a[i]==w)q++;
	}
	sort(b+1,b+1+x);
	for(int i=1;i<=x;i++){
		z+=b[i];
		//cout<<"z:"<<z<<endl;
		if(z>m)break;
		q++;
	}
	return q;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	long long l=1e18,r=-1e18,mid=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	//cout<<l<<" "<<r;
	while(l<=r){
		mid=(l+r)/2;
		//cout<<"mid:"<<mid<<endl;
		//cout<<"["<<l<<" "<<r<<endl;
		//cout<<check(mid)<<endl;
		if(check(mid)<=m){
			//ans=max(mid,ans);
			//cout<<ans<<endl;
			l=mid+1;
		}else{
			r=mid-1;
		}
		//cout<<ans<<endl;
	}
	//cout<<l<<" "<<r<<']'<<endl;
	cout<<find(r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
