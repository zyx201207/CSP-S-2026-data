#include<bits/stdc++.h>
using namespace std;
long long read(){
	int t=1,l=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		l=l*10+ch-'0';
		ch=getchar();
	}
	return t*l;
}
const int MX=2e5+5;
int n,m;
long long a[MX];
long long anss;
int ans[MX];
int er[MX][35];
bool b[MX];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	bool t=1;
	long long num=0;
	while(t){
		t=0;
		num++;
		for(int i=1;i<=n;i++){
			if(!a[i]) continue;
			t=1;
			er[i][0]++;
			er[i][er[i][0]]=(a[i]%2)?1:0;
			a[i]/=2;
		}
	}
	num--;
	for(int i=num;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(b[j]) continue;
			if(er[j][i]) sum++;
		}
		if(sum<m){
			ans[i]=0;
			continue;
		}
		ans[i]=1;
		for(int j=1;j<=n;j++){
			if(b[j]) continue;
			if(er[j][i]==0) b[j]=1;
		}
	}
	while(ans[num]==0) num--;
	long long cnt=1;
	for(int i=1;i<=num;i++){
		anss+=ans[i]*cnt;
		cnt*=2;
	}
	printf("%lld",anss);
	return 0;
}
