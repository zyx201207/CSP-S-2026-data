#include<bits/stdc++.h>	//1-10,11-12[?],13-17(17) 17*5=85[15*5=75]
#define ll long long
using namespace std;
//pow(2,i)
ll b[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
ll n,m,a[200005],ma,sum,ans,f_A=1,f_B=1,f_4=1,t[35],c[35],cnt,s[35];
void dfs(ll x,ll y,ll z){	//1-5
	if(x==n+1){
		if(z==m) ans=max(ans,y);
		return;
	}
	dfs(x+1,y,z);
	dfs(x+1,(y==0?a[x]:y&a[x]),z+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=18;i++){	//14-15(f_B)
		if(b[i]==n) break;
		if(i==18) f_B=0;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){	//13(f_A)
			if(a[i]==b[j]-1) break;
			if(j==30) f_A=0;
		}
		if(a[i]!=i-1) f_B=0;	//14-15(f_B)
		if(a[i]>=4) f_4=0;	//16-17(f_4)
	}
	if(n<=20){	//1-5
		dfs(1,0,0);
	}else if(m==n){	//7
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else if(m==1){	//6
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){	//8-10
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(f_A){	//13
		sort(a+1,a+1+n);
		ans=a[n-m+1];
	}else if(f_B){	//14-15
		ans=n;
		for(int i=18;i>=0;i--){
			if(m>=b[i]){
				ans-=b[i+1];
				break;
			}
		}
	}else if(f_4){	//16-17
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[3]>=m) ans=3;
		else if(t[3]+t[2]>=m) ans=2;
		else if(t[3]+t[1]>=m) ans=1;
		else ans=0;
	}else if(m==n-1){	//11-12?
		for(int i=1;i<=n;i++){
			cnt=a[i];
			for(int j=30;j>=0;j--){
				if(cnt>=b[j]) cnt-=b[j],t[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=30;j++){
				s[j]=t[j];
			}
			cnt=a[i];
			for(int j=30;j>=0;j--){
				if(cnt>=b[j]) cnt-=b[j],s[j]--;
			}
			cnt=0;
			for(int j=0;j<=30;j++){
				if(s[j]==m) cnt+=b[j];
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
/*
2 5 9 3 5
  10
 101
1001
  11
 101
*/
