#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e6+10;
int a[N];
int n,d;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}return x*f;
}int max(int _,int __){
	return _>__?_:__;
}int lrb(int l,int r,int x){
	int L=l,R=r;
	int ___=-1;
	while(L<=R){
		int mid=L+R>>1;
		if(a[mid]>=x){
			___=mid;
			R=mid-1;
		}else L=mid+1;
	}return ___;
}
int find(int l,int r){
	if(l>r) return 1;
	if(l==r) return 0;
	int c=lrb(l,r,a[l]+d);
	if(c==-1) return 1;
	else return find(c,r);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(n<4) cout<<0<<endl;
		else{
			int cha=a[2]-a[1];
			int fl=1;
			for(int i=3;i<=n;i++){
				if(a[i]-a[i-1]!=cha) fl=0;
			}if(fl==1){
				if(d/cha<2) cout<<0<<endl;
				else{
					int k=d/cha*2;
					cout<<max(0,n-k+1)<<endl; 
				}
			}else{
				int tt=0;
				for(int l=1;l<=n;l++){
					for(int r=l+3;r<=n;r++){
						int ci=find(l,r);
						if(ci==1) tt++;
					}
				}cout<<tt<<endl;
			} 
		}
	}
	return 0;
}

