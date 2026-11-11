#include <bits/stdc++.h>//o(n)
#include <map>
#include <vector>
#include <stack>
#define int long long
using namespace std;
const int N=2e5+5;
struct abc{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].c==a[r].c){
			int t1=a[l].x,t2=a[r].x;
			if(t1==t2)l++,r--;
			if(t1>t2){
				a[l].x-=a[r].x;
				r--;
			}
			if(t1<t2){
				a[r].x-=a[l].x;
				l++;
			}
		}else{
			int t1=a[l].x,t2=a[r].x;
			if(t1==t2)l++,r--,sum+=t1;
			if(t1>t2){
				a[l].x-=a[r].x;
				sum+=a[r].x;
				r--;
			}
			if(t1<t2){
				a[r].x-=a[l].x;
				sum+=a[l].x;
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
//start 0.5h
//end 1h
