#include<bits/stdc++.h>
using namespace std;
#define int long long
struct str{
	int sum;
	char c;
}a[200005];
int q[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
		q[i]=q[i-1]+a[i].sum; 
	}
//	int top1=1,top2=n;
//	int ans=0;
//	for(int i=1;i<=a[n].sum/2;i++){
//		if(i>a[top1].sum) top1++;
//		if(a[n].sum+1-i<=a[top2-1].sum) top2--;
//		if(a[top1].c!=a[top2].c) ans++; 
//	}
//	cout<<ans;
    int p;
	for(int i=1;i<=n;i++){
		if(q[i]>q[n]/2){
			p=i;
			if(q[n]%2) a[i].sum--;
			break;
		}
	}
	int top=n;
	int ans=0;
	for(int i=1;i<p;i++){
		int sum=0,sumc=0;
		while(sum<a[i].sum){
			sum+=a[top].sum;
			if(a[top].c!=a[i].c){
				if(sum<=a[i].sum) sumc+=a[top].sum;
				else {
					sumc+=a[i].sum-sum+a[top].sum;
				}
			}
			if(sum>a[i].sum){
				a[top].sum-=a[i].sum-sum+a[top].sum;
				top++;
			}
			top--;
		}
		ans+=sumc;
	}
	cout<<ans;
	return 0;
} 
