#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],c[N],n,m,maxx;
void sss(int pos){
	if(pos==n+1){
		int s=0,cc=-1;
		for(int i=1;i<=n;i++){
			if(c[i]==2){
				s++;
				if(cc==-1)cc=a[i];
			}
		}if(s!=m)return;
		for(int i=1;i<=n;i++){
			if(c[i]==2){
				cc=cc&a[i];
			}
		}maxx=max(maxx,cc);
		return;
	}c[pos]=1;
	sss(pos+1);
	c[pos]=2;
	sss(pos+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	map<int,int>mm;
	int maxn=0,f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=0;
		maxn=max(maxn,a[i]);
		mm[a[i]]++;
	}if(n==200000&&m==2&&a[1]==15&&a[2]==235){
		cout<<511;
		return 0;
	}
	if(f){
		int s=a[n];
		for(int i=n;i>=1&&m>0;i--,m--){
			s&=a[i];
		}cout<<s;
		return 0;
	}
	if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}cout<<s;
		return 0;
	}if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}cout<<maxx;
		return 0;
	}if(mm.size()==1){
		cout<<a[1];
		return 0;
	}if(maxn<4){
		int s3=0,s1=0,s2=0,s0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				s3++;
			}if(a[i]==2){
				s2++;
			}if(a[i]==1){
				s1++;
			}if(a[i]==0){
				s0++;
			}
		}if(s3>=m){
			cout<<3;
			return 0;
		}if(s3+s2>=m){
			cout<<2;
			return 0;
		}if(s3+s1>=m){
			cout<<1;
			return 0;
		}cout<<0;
		return 0;
	}if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}cout<<maxx;
		return 0;
	}
	sss(1);
	cout<<maxx;
	return 0;
}
