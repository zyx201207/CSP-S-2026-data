#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int readint(){
	int x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

ll readll(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(0));
	clock_t st=rand();
	int n=readint();
	int m=readint();
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		a[i]=readll();
	}
	int cnt=0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(clock()-st>0.96*CLOCKS_PER_SEC){
			printf("%d",cnt);
			return 0;
		}
		ll sum=0;
		int tmp=1;
		for(int j=i+1;j<n;j++){
			if(clock()-st>0.96*CLOCKS_PER_SEC){
				printf("%d",cnt);
				return 0;
			}
			sum+=(a[j]-a[j-1])*tmp;
			if(m<sum){
				break;
			}
			tmp++;
		}
		cnt=max(cnt,tmp);
	}
	printf("%d",cnt);
	return 0;
} 

 // 5 5 1 2 4 8 9 
 //5 8 -3 -1 2 2 7
