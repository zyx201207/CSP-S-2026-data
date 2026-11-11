#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
struct node{
	ll num;
	char c;
}a[MAXN],b[MAXN];
ll n,sa=1,sb=1,ans,cnt,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	for(int i=1;i<=n;i++){
		b[i].num=a[n-i+1].num,b[i].c=a[n-i+1].c;
	}
	while(1){
		if(a[sa].c==b[sb].c){
			if(cnt+min(a[sa].num,b[sb].num)<=sum/2){
				if(a[sa].num<b[sb].num){
					b[sb].num-=a[sa].num;
					cnt+=a[sa].num;
					sa++;
				}
				else if(a[sa].num>b[sb].num){
					a[sa].num-=b[sb].num;
					cnt+=b[sb].num;
					sb++;
				}
				else{
					cnt+=a[sa].num;
					sa++;
					sb++;
				}
			}
			else{
				break;
			}
		}
		else{
			if(cnt+min(a[sa].num,b[sb].num)<=sum/2){
				if(a[sa].num<b[sb].num){
					b[sb].num-=a[sa].num;
					ans+=a[sa].num;
					cnt+=a[sa].num;
					sa++;
				}
				else if(a[sa].num>b[sb].num){
					a[sa].num-=b[sb].num;
					ans+=b[sb].num;
					cnt+=b[sb].num;
					sb++;
				}
				else{
					ans+=a[sa].num;
					cnt+=a[sa].num;
					sa++;
					sb++;
				}
			}
			else{
				ans+=sum/2-cnt;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
