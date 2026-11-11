#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=200010;
int a[N],be[35];
bool b[N][35],ch[N];
int ans;
int read(){
	int k=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k;
}
int ten_to_two(int x,int le){
	int u=a[x];
	int k=le;
	while((1<<k)<u)k++;
	if(u!=(1<<k))k--;
	b[x][k]=true;
	be[k]++;
	u=u-(1<<k);
	int i=k;
	while(u){
		if(u>=(1<<i)){
			b[x][i]=true;
			be[i]++;
			u=u-(1<<i);
		}
		i--;
	}
	return k;
}
void choose(int t,int k){
	int u=k;
	for(int i=t;i>=0;i--)
		if(be[i]>=m){
			for(int j=1;j<=n;j++)
				if(ch[j]&&!b[j][i]){
					ch[j]=false;u--;
					for(int k=0;k<=t;k++)
						if(b[j][k])be[k]--;
				}
			if(u>m)choose(t-1,u);
			return;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	int idx=0,t=0;
	for(int i=n;i>=1;i--){
		if(a[i]==0)idx++;
		else t=ten_to_two(i,t);
	}
	n=n-idx;
	if(n<m){
		printf("0");
		return 0;
	}
	memset(ch,true,sizeof(ch));
	choose(t,n);
	for(int i=n;i>=1;i--)
		if(ch[i]){
			if(ans==0)ans=a[i];
			else ans=ans&a[i];
		}
	printf("%d",ans);
	return 0;
}
