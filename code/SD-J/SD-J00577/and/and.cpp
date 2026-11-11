#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int c,ch[N],mxans;
bool test_1_5,test_6,test_7,test_8_10,test_11_12,test_13=1,test_14_15=1,test_16_17=1,test_18_19=1;//х╚йгльеп:( 
/*
void dfs(int x){
	if(c==m){
		int tans=ch[1];
		for(int i=2;i<=c;i++){
			tans&=a[i];
		}
		mxans=max(mxans,tans);
		return;
	}
	if(x==n){
		return;
	}
	dfs(x++);
	ch[++c]=a[x];
	dfs(x);
	c--;
}
*/
int check(int x){
	int r=0;
	while(x){
		x&=x-1;
		r++;
	}
	return r;
}
int get(int x){
	int r=0;
	while(x){
		x/=2;
		r++;
	}
	return r;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			test_16_17=0;
		}
		if((a[i]+1)&a[i]!=0){
			test_13=0;
		}
		if(a[i]>=1024){
			test_18_19=0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			test_14_15=0;
			break;
		}
	}
	if(n<=20){
		test_1_5=1;
		int mxans=0;
		for(int i=0;i<(1<<n);i++){
			if(check(i)==m){
				int ti=i;
				int tans=(1<<30)-1;
				while(ti>0){
					tans&=a[get(lowbit(ti))];
					ti-=lowbit(ti);
				}
				mxans=max(mxans,tans);
			}
		}
		cout<<mxans;
	}else if(m==1){
		test_6=1;
		cout<<a[n];
	}else if(m==n){
		test_7=1;
		int tans=(1<<30)-1;
		for(int i=1;i<=n;i++){
			tans&=a[i];
		}
		cout<<tans;
	}else if(m==2){
		test_8_10=1;
		int mxans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mxans=max(mxans,a[i]&a[j]);
			}
		}
		cout<<mxans;
	}else if(m==n-1){
		test_11_12=1;
		int mxans=0;
		for(int i=1;i<=n;i++){
			int tans=(1<<30)-1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					tans&=a[j];
				}
			}
			mxans=max(mxans,tans);
		}
		cout<<mxans;
	}else if(test_13){
		int tans=(1<<30)-1;
		for(int i=n;i>=n-m+1;i--){
			tans&=a[i];
		}
		cout<<tans;
	}else if(test_14_15){
		if(m<=n/2){
			int tans=(1<<30)-1;
			for(int i=n;i>=n-m+1;i--){
				tans&=a[i];
			}
			cout<<tans;
		}else{
			cout<<0;
		}
	}else if(test_16_17){
		int num[4];
		for(int i=1;i<=n;i++){
			num[a[i]]++;
		}
		if(num[3]>=m){
			cout<<3;
		}else if(num[3]+num[2]>=m){
			cout<<2;
		}else if(num[3]+num[1]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		int mxans=0;
		for(int i=0;i<(1<<n);i++){
			if(check(i)==m){
				int ti=i;
				int tans=(1<<30)-1;
				while(ti>0){
					tans&=a[get(lowbit(ti))];
					ti-=lowbit(ti);
				}
				mxans=max(mxans,tans);
			}
		}
		cout<<mxans;
	}
	return 0;
}
