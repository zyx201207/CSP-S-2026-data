#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n; 
long long ans=0,f1=1,f2;
struct iString{
	long long num;
	char f;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].f;
	}
	f2=n;
	while(f1<f2){
		if(a[f1].f!=a[f2].f){
			if(a[f1].num>a[f2].num) {
				a[f1].num-=a[f2].num;
				ans+=a[f2].num;
				f2-=1;
			}
			else if(a[f1].num<a[f2].num) {
				a[f2].num-=a[f1].num;
				ans+=a[f1].num;
				f1+=1;
			}
			else {
				f1+=1;
				f2-=1;
				ans+=a[f1].num;
			}
		}
		if(a[f1].f==a[f2].f){
			if(a[f1].num>a[f2].num) {
				a[f1].num-=a[f2].num;
				f2-=1;
			}
			else if(a[f1].num<a[f2].num) {
				a[f2].num-=a[f1].num;
				f1+=1;
			}
			else {
				f1+=1;
				f2-=1;
			}
		}
	} 
	cout<<ans;
	return 0;
} 
