#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N];
int ans[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long nw=a[1];
	ans[0]=0;
	int t;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+1;
		t=ans[i-1];
		if(nw<a[i]){
			while((m<t*(a[i]-nw))&&t>=0){
				m+=nw-a[i-t];
				t--;ans[i]--;
			}
		}
		if(t<0){
			ans[i]=0;
			break;
		}
		m-=t*(a[i]-nw);
		nw=a[i];
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		if(ma<ans[i]){
			ma=ans[i];
		}
	}
	printf("%d",ma);
	fclose(stdin);
	fclose(stdout);
	return 0;
}