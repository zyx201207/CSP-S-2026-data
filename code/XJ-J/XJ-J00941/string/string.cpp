#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
struct node{
	char s;
	long long n;
}a[N];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].n>>a[i].s;
	}
	long long l=1,r=n,num1=a[l].n,num2=a[r].n,minn;
	while (l<r){
		minn=min(num1,num2);
		if (a[l].s!=a[r].s){
			ans+=minn;
		}
		num1-=minn;
		num2-=minn;
		if (num1==0){
			l++;
			num1+=a[l].n;
		}
		if (num2==0){
			r--;
			num2+=a[r].n;;
		}
	}
	cout<<ans;
	return 0;
} 
