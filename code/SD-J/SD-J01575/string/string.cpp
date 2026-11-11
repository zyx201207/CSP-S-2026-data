#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
struct L{
	long long x;
	char y;
}a[N]; 
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		sum+=a[i].x;
	}
	int ans=0,cnt=0;
	for(int i=1,j=n;cnt<ceil(sum/2);){
		if(a[i].y!=a[j].y){
			if(a[i].x>a[j].x){
				cnt+=a[j].x;
				ans+=a[j].x;
				a[i].x-=a[j].x;
				a[j].x=0;
				j--;
			}
			else if(a[i].x<a[j].x){
				cnt+=a[i].x;
				ans+=a[i].x;
				a[j].x-=a[i].x;
				a[i].x=0;
				i++;
			}
			else{
				cnt+=a[i].x;
				ans+=a[i].x;
				a[i].x=0;
				a[j].x=0;
				i++;
				j--;
			}
		}
		else{
			if(a[i].x>a[j].x){
				cnt+=a[j].x;
				a[i].x-=a[j].x;
				a[j].x=0;
				j--;
			}
			else if(a[i].x<a[j].x){
				cnt+=a[i].x;
				a[j].x-=a[i].x;
				a[i].x=0;
				i++;
			}
			else{
				cnt+=a[i].x;
				a[i].x=0;
				a[j].x=0;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

