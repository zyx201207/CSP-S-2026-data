#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5;
inline int fr(){
	int k=1,s=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
int a[N],qian[N];
int l,r,m,n;
int cha(int ll,int rr){
	return qian[rr]-qian[ll]
	-(ll-1)*(a[rr]-a[ll]);
}
bool kan(int len){
	for(int i=1;i<=n-len+1;i++){
		if(cha(i,i+len-1)<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=fr(); m=fr();
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		qian[i]=(a[i]-a[i-1])*(i-1)+qian[i-1];
	}
	l=1,r=m;
	while(l!=r && r-l!=1){
		int mid=(l+r)/2;
		if(kan(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

