#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans;
int n,cnt1=1,cnt2;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		cin>>a[i].c;
	}
	cnt2=n;
	while(cnt1<cnt2){
		if(a[cnt1].c==a[cnt2].c){
			if(a[cnt1].x<a[cnt2].x){
				a[cnt2].x-=a[cnt1].x;
				cnt1++;
			}
			else if(a[cnt1].x==a[cnt2].x){
				cnt1++;
				cnt2--;
			}
			else if(a[cnt1].x>a[cnt2].x){
				a[cnt1].x-=a[cnt2].x;
				cnt2--;
			}
		}
		else{
			if(a[cnt1].x<a[cnt2].x){
				ans+=a[cnt1].x;
				a[cnt2].x-=a[cnt1].x;
				cnt1++;
			}
			else if(a[cnt1].x==a[cnt2].x){
				ans+=a[cnt1].x;
				cnt1++;
				cnt2--;
			}
			else if(a[cnt1].x>a[cnt2].x){
				ans+=a[cnt2].x;
				a[cnt1].x-=a[cnt2].x;
				cnt2--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
