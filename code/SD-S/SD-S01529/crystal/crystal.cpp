#include<bits/stdc++.h>

#define int long long

using namespace std;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch > '9'||ch < '0'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	char ch = x%10+'0';
	if(x >= 10) print(x/10);
	putchar(ch);
}

int n,m;
int a[500005];
int qzh[500005];
int ans;

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n = read();m = read();
	for(int i = 1;i <= n;++ i)
		a[i] = read();
	
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;++ i)
		qzh[i] = qzh[i-1]+a[i];
	
	for(int i = 1;i <= n;++ i){
		//以a[i]为标准
		int l = 1,r = i;
		while(l < r){
			int mid = (l+r)/2;
			int ned = a[i]*(i-mid+1)-(qzh[i]-qzh[mid-1]);
			if(ned <= m) r = mid;
			else l = mid+1;
		}
		ans = max(ans,i-r+1);
	}
	
	print(ans);
	
	return 0;
	
}
