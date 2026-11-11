#include<bits/stdc++.h>

using namespace std;
long long n,m;
long long a[200010];

int getDigit(int n){
	int ans=0;
	while(n>0){
		n>>=1;
		ans++;
	}
	return ans;
}
int getbit(int n){
	int ans=0;
	while(n>0){
		n&=(n-1);
		ans++;
	}
	return ans;
}
int lowbit(int n){
	return n&-n;
}
bool cmp(int a,int b){
	if(lowbit(a)==lowbit(b)){
		if(getbit(a)==getbit(b)){
			return getDigit(a)<getDigit(b);
		}
		else return getbit(a)>getbit(b);
	}
	else return lowbit(a)>lowbit(b);
}
int main(){
	freopen("and3.in","r",stdin);
//	freopen("and.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a,a+n,cmp);
	long long ans=-1;
	for(int i=0;i<m;i++){
		ans&=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}

