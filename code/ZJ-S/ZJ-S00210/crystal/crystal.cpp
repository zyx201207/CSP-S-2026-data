#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int n;
ull m;
int cnt=0;//计数
ll a[500005];
ll b[500005];//差分数组

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int temp=a[(n/2)];
	
	for(int i=1;i<=n;i++){
		b[i]=fabs(a[i]-temp);

	}



	sort(b+1,b+n+1);
	
	for(int i=1;i<=n;i++){
		if(m<b[i]){
			cout<<cnt;
			return 0;
			}
			m-=b[i];
			cnt++;
		}
		cout<<cnt;
	return 0;
}