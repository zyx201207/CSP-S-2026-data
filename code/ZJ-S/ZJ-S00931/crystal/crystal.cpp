#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],ch[600000],maxn=1,ans,id,sum;
bool A,B;
inline int read(){
	long long f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	A=true,B=true;
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=i) A=false;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(!(i<=2||(a[i]==a[i-1]&&a[i-1]==a[i-2]))){
			B=false;
		}
	}
	if(A){
		sum=0;
		for(int i=1;i<=n;i++){
			if(sum+i>m)
			sum+=i;
			else
			cout<<i<<"\n";
		}	
		return 0;
	}else if(B){
		sum=0;
		for(int i=1;i<=n;i++){
			if(sum+a[2]-a[1]>m){
				sum=sum+a[2]-a[1];
			}else{
				cout<<i<<"\n";
			}
		}
		return 0;
	}
	
	for(int i=2;i<=n;i++){
		ch[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		ans=0;
		id=1;
		sum=0;
		for(int j=i-1;j>=1;j--){
			sum+=ch[j+1];
			ans+=sum;
			if(ans>m) break;
			id++;
		}
		maxn=max(maxn,id);
	}
	cout<<maxn;
	return 0;
}
