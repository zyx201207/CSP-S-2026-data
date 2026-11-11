#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct node{
	int sum;
	char ch;
}a[N];
long long ans;
bool f=1;
void hw1(){
	for(int i=2;i<=n;i++){
		if(a[i].ch!=a[1].ch){
			f=false;
		}
	}
}
void hw2(){
	for(int i=1;i<=n/2;i++){
		if(a[i].ch!=a[n-i+1].ch||a[i].sum!=a[n-i+1].sum){
			f=false;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i].sum,&a[i].ch);
	}
	hw1();
	if(f){
		printf("0");
		return 0;
	}
	f=1;
	hw2();
	if(f){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(a[i].ch!=a[n-i+1].ch){
			if(a[i].sum>=a[n-i+1].sum){
				ans+=a[n-i+1].sum;
				a[n-i+1].ch=a[i].ch;
			}
			else{
				ans+=a[i].sum;
				a[i].ch=a[n-i+1].ch;
			}
		}
	}
	f=1;
	hw1();
	if(f){
		printf("%lld",ans);
		return 0;
	}
	f=1;
	hw2();
	if(f){
		printf("%lld",ans);
		return 0;
	}	
	for(int i=1;i<=n/2;i++){
		if(a[i].sum!=a[n-i+1].sum){
			if(a[i].sum>a[n-i+1].sum){
				ans+=abs(a[i].sum-a[n-i+1].sum);
				a[n-i+1].sum+=abs(a[i].sum-a[n-i+1].sum);
				a[n-i].sum-=abs(a[i].sum-a[n-i+1].sum);
			}
			else{
				ans+=abs(a[i].sum-a[n-i+1].sum);
				a[i].sum+=abs(a[i].sum-a[n-i+1].sum);
				a[i+1].sum-=abs(a[i].sum-a[n-i+1].sum);
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
