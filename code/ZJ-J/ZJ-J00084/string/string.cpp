#include <bits/stdc++.h>
using namespace std;
long long sum=0,ans=0;
struct node{
	long long geshu=0;
	char zifu;
}a[200005];
node b[200005],c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].geshu >> a[i].zifu;
		sum+=a[i].geshu;
	}
	long long cut = ceil((double)sum/2);
	long long left = 0;
	long long cutd = 0;
	int flag = 0;
	int falg = 1;
	for(int i=1;i<=n;i++){
		if(flag==0){
			left+=a[i].geshu;
			b[i].geshu=a[i].geshu;
			b[i].zifu=a[i].zifu;
		}else{
			c[i-cutd].geshu=a[i].geshu;
			c[i-cutd].zifu=a[i].zifu;
		}
		if(left==cut&&flag==0){
			falg = 0;
			flag = 1;
			cutd = i;
		}else if(left>cut&&flag==0){
			int x = left-cut;
			flag = 1;
			cutd = i-1;
			c[i-cutd].geshu=x;
			c[i-cutd].zifu=a[i].zifu;
			b[i].geshu=a[i].geshu-x;
		}
	}
	long long sumn = sum;
	long long bn = cutd+falg;
	if(sumn%2==1){
		sumn--;
		b[bn].geshu--;
	}
	long long i=bn,j=1;
	while(i>=1){
		long long pwp = min(b[i].geshu,c[j].geshu);
		if(b[i].zifu==c[j].zifu){
			b[i].geshu-=pwp;
			c[j].geshu-=pwp;
		}else{
			b[i].geshu-=pwp;
			c[j].geshu-=pwp;
			ans+=pwp;
		}
		if(b[i].geshu==0){
			i--;
		}
		if(c[j].geshu==0){
			j++;
		}
	}
	cout << ans << endl;
	return 0;
}