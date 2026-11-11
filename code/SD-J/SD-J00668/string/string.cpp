#include<bits/stdc++.h>
using namespace std;
struct s{
	long long num;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,L=0,head=1,tail=0,ans=0;
	cin>>n;
	tail=n;
	for(long long i=1;i<=n;++i){
		cin>>a[i].num>>a[i].c;
		L+=a[i].num;
	}
	while(tail>head){
		if(a[tail].c!=a[head].c){
			if(a[tail].num>a[head].num){
				a[tail].num-=a[head].num;
				ans+=a[head].num;
				head++;
			}else if(a[tail].num<a[head].num){
				ans+=a[tail].num;
				a[head].num-=a[tail].num;
				tail--;
			}else{
				ans+=a[head].num;
				tail--;
				head++;
			}
		}else{
			if(a[tail].num>a[head].num){
				a[tail].num-=a[head].num;
				head++;
			}else if(a[tail].num<a[head].num){
				a[head].num-=a[tail].num;
				tail--;
			}else{
				tail--;
				head++;
			}
		}
	}cout<<ans;
}
