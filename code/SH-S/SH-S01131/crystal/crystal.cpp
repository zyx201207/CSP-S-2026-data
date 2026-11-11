#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500009;
int n,m,a[N],ans=1;
struct Node{
	int x,num,c,num1;
}sum[N];
bool cmp(Node p,Node q){
	return p.x<q.x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	int cnt=1;
	sum[1].x=a[1];
	sum[1].num=sum[1].num1=1;
	bool ok=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			ok=0;
			break;
		}
	}
//	cout<<ok<<endl;
	if(ok){
		int w=sqrt(2*m);
		cout<<w<<'\n';
		return 0;
	}
	ok=1;
	int d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			ok=0;
			break;
		}
	}
	if(ok){
		int w=(-d+sqrt(d*d-(d*a[1]-2*d*m-a[1]*a[1])*(d*a[1]-2*d*m-a[1]*a[1])))/2;
		cout<<w<<'/n';
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			sum[cnt].num++;
			sum[cnt].num1++;
		}
		else{
			cnt++;
			sum[cnt].num++;
			sum[cnt].num1++;
			sum[cnt].x=a[i];
		}
//		cout<<cnt<<" "<<sum[cnt].x<<" "<<sum[cnt].num<<endl;
	}
//	for(int i=1;i<=cnt;i++)cout<<sum[i].x<<" "<<sum[i].num<<endl;
//	cout<<cnt<<endl;
	sum[1].c=0;
	for(int i=2;i<=cnt;i++){
		int t=m;
		for(int j=i-1;j>=1;j--){
			if(t<sum[i].x-sum[j].x)break;
			int cha=sum[i].x-sum[j].x;
			if((t/cha)<sum[j].num1){
				sum[i].num+=t/cha;
				break;
			}
			else{
				sum[i].num+=sum[j].num1;
				t-=sum[j].num1*cha;
			}
		}
		ans=max(ans,sum[i].num);
	}
	cout<<ans<<'\n';
	return 0;
} 
