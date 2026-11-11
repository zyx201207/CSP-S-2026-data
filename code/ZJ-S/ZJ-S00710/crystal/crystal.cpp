#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5000;
#define int long long

int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+(int)(c-'0');
		c=getchar();
	}
	return k*f;
}
int n,m,a[maxn],s[maxn],ans;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
//	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
