#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct strs{
	long long cnt;
	char num;
}a[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
//	scanf("%d\n",&n);
	cin>>n;
	long long b;
	char c;
	for(int i=0;i<n;i++){
//		scanf("%lld ",&b);
//		scanf("%c\n",&c);
		cin>>b>>c;
		a[i].cnt=b;
		a[i].num=c;
	}
	int l=0,r=n-1;
	while(l<r){
		if(a[l].cnt==a[r].cnt&&a[l].num!=a[r].num){
			ans+=a[l].cnt;
			a[l].cnt=0;
			a[r].cnt=0;
		}
		else if(a[l].cnt==a[r].cnt&&a[l].num==a[r].num){
			a[l].cnt=0;
			a[r].cnt=0;
		}
		else if(a[l].cnt>=a[r].cnt&&a[l].num==a[r].num){
			a[l].cnt=a[l].cnt-a[r].cnt;
			a[r].cnt=0;
		}
		else if(a[l].cnt>=a[r].cnt&&a[l].num!=a[r].num){
			ans+=a[r].cnt;
			a[l].cnt=a[l].cnt-a[r].cnt;
			a[r].cnt=0;
		}
		else if(a[l].cnt<=a[r].cnt&&a[l].num==a[r].num){
			a[r].cnt=a[r].cnt-a[l].cnt;
			a[l].cnt=0;
		}
		else if(a[l].cnt<=a[r].cnt&&a[l].num!=a[r].num){
			ans+=a[l].cnt;
			a[r].cnt=a[r].cnt-a[l].cnt;
			a[l].cnt=0;
		}
		if(a[l].cnt==0){
			l++;
		}
		if(a[r].cnt==0){
			r--;
		}
	}
//	printf("%d",ans);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
