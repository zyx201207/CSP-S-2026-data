#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,cnt=0;
long long a[N],d;
int solve(int l,int r){
	int cnt=0;
	for(int i=l;i<r;i++){
		if(a[i+1]-a[i]>d) return 0;
	}
	for(int k=2;k<=r-l;k++){
		for(int i=l;i<=r-k;i++){
			if(a[i+k]-a[i]<=d) cnt++;
		}
	}
	if(cnt==2) return 1;
	else return 0;
}
long long read(){
	long long s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	c=read();t=read();
	while(t--){
		cnt=0;
		n=read();d=read();
		for(int i=1;i<=n;i++) a[i]=read(); 
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt+=solve(i,j);
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
} 
