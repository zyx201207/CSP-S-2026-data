#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;

int n;
long long ans;
struct put{
	int num;
	string s1;
}a[MAXN];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].s1;
	int l=1,r=n;
	while(l<r){
		if(a[l].s1!=a[r].s1){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				ans+=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				ans+=a[l].num;
				l++;
			}
			else{
				ans+=a[l].num;
				l++,r--;
			}
		}
		else{
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
