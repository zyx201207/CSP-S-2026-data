#include<bits/stdc++.h>
using namespace std;
const int N=2e5+66;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%d",&n);
	int q=time(0);
	//cout<<n<<'\n';
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	while(!(c[i]>='a'&&c[i]<='z'))c[i]=getchar();
	//cout<<i<<' '<<a[i]<<' '<<c[i]<<'\n';
	}
	int o1=1,o2=n;
	long long ans=0;
	while(o2>o1){
	//cout<<o1<<' '<<o2<<' '<<a[o1]<<' '<<a[o2]<<' ';
	if(c[o1]!=c[o2])ans+=min(a[o1],a[o2]);
	if(a[o1]>a[o2]){
	a[o1]-=a[o2];
	a[o2]=0;
	}
	else a[o2]-=a[o1],a[o1]=0;
	//cout<<o1<<' '<<o2<<' '<<a[o1]<<' '<<a[o2]<<' ';
	if(a[o1]==0) o1++;
	if(a[o2]==0) o2--;
	//cout<<o1<<' '<<o2<<'\n';
	}
	printf("%lld",ans);
	
	return 0;
} 
