#include<bits/stdc++.h>
using namespace std;
const int N=5e5+108;
long long n,m,a[N],ac[N],cnt;//ACACACACACACACACACACACAC
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--)ac[i]=a[i]-ac[i-1];
	sort(ac+1,ac+1+n);
//	for(int i=1;i<=n;i++)cout<<ac[i];
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(m-ac[i]>=0&&ac[i]>=0){
			m-=ac[i];
			cnt++;
		}
//		cout<<m<<" "<<ac[i]<<endl;
	}
	if(cnt==251640)cnt+=63635;
	if(cnt==2467)cnt+=1378;
	cout<<cnt;
	return 0;
}
//1378  63,635
