#include<bits/stdc++.h>
#define ll long long
#define bug(x) cout<<"----------"<<(x)<<"----------"<<endl;
using namespace std;
int n,m,q[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
struct node{
	int cnt1,a;
}a[200005];
int ans;
bool cmp(node a,node b){
	if(a.cnt1==b.cnt1){
		return a.a>b.a;
	}
	return a.cnt1>b.cnt1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
	}
	for(int i=1;i<=n;i++){
		int f=a[i].a;
		for(int j=30;j>=0;j--){
			if(f>=q[j]){
				f-=q[j];
				a[i].cnt1++;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].a;
	for(int i=2;i<=m;i++){
		ans&=a[i].a;
	}
	cout<<ans;
	return 0;
}
