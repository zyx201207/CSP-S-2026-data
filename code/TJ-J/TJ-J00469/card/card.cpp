#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int a[N],b[N],sum[N];
int tong[N];
int ans[N];
int read(){
	char ch;
	int x=0,f=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}return x*f;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int fl=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) fl=0;
	}if(fl==1){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+b[i];
		}for(int i=1;i<=a[n];i++) cout<<sum[i]<<' ';
		return 0;
	}else if(m<=2){
		if(m==1) cout<<n;
		else{
			int s1=0,s2=0;
			for(int i=1;i<=n;i++){
				int l=b[i],r=b[n];
				if(l==1&&r==1) s1++;
				if(l==1&&r==2){
					s1++;
					s2++;
				}if(l==2&&r==1){
					s1++;
					s2++;
				}if(l==2&&r==2) s2++;
			}cout<<s1<<' '<<s2;
		}return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) tong[j]=0;
			for(int j=i;j<=n;j++){
				if(tong[a[j]]==0){
					tong[a[j]]=j;
				}else{
					for(int k=tong[a[j]]+1;k<=j;k++){
						tong[a[k]]=0;
					}tong[a[j]]=j;
				}
			}for(int j=1;j<=m;j++){
				if(tong[j]>0) ans[j]++; 
			}
		}for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}
	return 0;
}

