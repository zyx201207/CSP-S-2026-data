#include <bits/stdc++.h>
using namespace std;
char b[200005];
long long a[200005];
long long n,cnt=0;
long long qians=0,hous=0;
void shan(long long x,char p,long long y,char q){
	if(x>=y&&p==q){
		x-=y;
		y=0;
	}
	else if(x>=y&&p!=q){
		x-=y;
		cnt+=y;
		y=0;
	}
	else if(x<y&&p==q){
		y-=x;
		x=0;
	}
	else {
		y-=x;
		cnt+=x;
		x=0;
	}
	qians=x;
	hous=y;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(l<=r){
		if(a[l]!=0&&a[r]!=0){
			shan(a[l],b[l],a[r],b[r]);
			a[l]=qians;
			a[r]=hous;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<cnt;
	return 0;
}