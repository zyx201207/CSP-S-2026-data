#include<bits/stdc++.h>
using namespace std;
inline int readi(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
inline long long readl(){
	long long s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
long long a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=readi();
	long long m=readl();
	for(int i=1;i<=n;i++){
		a[i]=readl();
	}
	sort(a+1,a+1+n);
	int dengcha=1;
	long long kk=a[n]-a[n-1];
	for(int i=n-1;i>=2;i--){
		if(kk!=a[i]-a[i-1]) dengcha=0;
	}
	if(dengcha==1){
		if(kk==0){
			cout<<n;
			return 0;
		}
		int anbs=1;
		for(int i=n-1;i>=1;i--){
			if(m-kk>=0){
				m-=kk;
				kk+=kk;
				anbs++;
			}
		}
		cout<<anbs;
		return 0;
	}
	int ans=1;
	long long mm=m;
	long long cha;
	for(int i=n;i>=2;i--){
		if(ans>=i) break; 
		m=mm;
		int anss=1;
		long long rmid=a[i];
		for(int j=i-1;j>=1;j--){
			cha=rmid-a[j];
			if(m-cha>=0){
				m-=cha;
				anss++;
			}
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}
