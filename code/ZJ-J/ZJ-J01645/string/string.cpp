#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
long long L[N],R[N];
char c[N];
long long len,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		L[i]=len+1;
		len+=a[i];
		R[i]=len;
	}
	long l=0,r=len+1;
	int i=1,j=n;
	while(i<j){
		long long x=R[i]-l,y=r-L[j];
		if(c[i]!=c[j]){
			if(x>y)ans+=y;
			else ans+=x;
		}
		if(x>y){
			l=l+y;
			r=r-y;
			j--;
		}else if(x==y){
			l=R[i];
			r=L[j];
			i++;
			j--;
		}else{
			l=l+x;
			r=r-x;
			i++;
		}
	}
	printf("%lld",ans);
	return 0;
}