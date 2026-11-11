#include<bits/stdc++.h>
using namespace std;
int n,m;
long long l;
long long a[200010];
char b[200010];
long long c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(i>1 && b[i]==b[i-1]){
			a[i-1]+=a[i];
			n--,i--;
		}
	}if(n==1){
		cout<<ans;
		return 0;
	}for(int i=1;i<=n;i++){
		c[i]=l;
		l+=a[i];
	}for(int i=1;i<=n;i++){
		if(c[i]+a[i]>(l-1)/2){
			m=i;
			break;
		}
	}long long i=0,j=0,x=0,y=0;
	if(l%2==0){
		if(l/2-c[m]<c[m+1]-l/2) i=m-1,j=m;
		else i=m,j=m+1;
		int t=min(l/2-c[m],c[m+1]-l/2);
		x=l/2-t-1,y=l/2+t;
	}else{
		if((l-1)/2-c[m]<c[m+1]-(l-1)/2-1) i=m-1,j=m;
		else i=m,j=m+1;
		int t=min((l-1)/2-c[m],c[m+1]-(l-1)/2-1);
		x=(l-1)/2-t-1,y=(l-1)/2+t+1;
	}for(;i>=1 && j<=n && x>=0 && y<l;){
		bool f=true;
		long long lt=x-c[i]+1,rt=c[j]+a[j]-y;
		if(b[i]==b[j]) f=false;
		if(lt>rt){
			if(f) ans+=rt;
			j++,x-=rt,y+=rt;
		}else if(lt<rt){
			if(f) ans+=lt;
			i--,x-=lt,y+=lt;
		}else{
			if(f) ans+=lt;
			i--,j++,x-=lt,y+=rt;
		}
	}cout<<ans;
	return 0;
}
