#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
unsigned int a[N],pos,xn,ans;
int n,m;
bool cmp(unsigned a,unsigned b){
	return ((a>>pos)&1u)>((b>>pos)&1u);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);//cout<<n;
	for(int i=1;i<=n;i++){
		scanf("%u",&a[i]);
	}xn=n;
	for(int i=30;i>=0;i--){
		pos=i;
		sort(a+1,a+1+xn,cmp);
		int cnt=0;
		for(int j=1;j<=xn;j++){
			//cout
			if((a[j]>>pos)&1u)cnt++;
			else break;
		}
		//cout<<i<<' '<<cnt<<' '<<xn<<endl;
		if(cnt>=m)xn=cnt;
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		//cout<<a[i]
		ans&=a[i];
	}printf("%u",ans);
	return 0;
}