#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,cnt=0;
bool flag=0;
long long m,a[N],sum[N];
int read(){
	int s=0,f=1;
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
int solve(int x){
	for(int i=x;i>=1;i--){
		if(sum[x]-sum[i]>m){
			return x-i;
		} 
	}
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	n=read();m=read();
	if(m==0){
		int cnt=0;
		map<long long,int> mp;
		for(int i=1;i<=n;i++){
			a[i]=read();
		 	if(mp.count(a[i])){
				mp[a[i]]++;		 		
			}
			else mp[a[i]]=1;
			if(mp[a[i]]>cnt) cnt=mp[a[i]];
		}
		cout<<cnt;
		return 0;	
	}
	int mp;
	a[1]=read();
	for(int i=2;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]+a[i]-a[i-1];
		if(!flag&&sum[i]>m) mp=i,flag=1;
	}
	sort(a+1,a+n+1);
	int cnt=mp-1;
	//cout<<mp<<" "<<sum[mp]<<"\n";
	for(int i=mp;i<=n;i++){
		cnt=max(cnt,solve(i));
	}
	cout<<cnt;
	return 0;
} 
