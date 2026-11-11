#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5e5;
const int mod=998244353;
int n;
int ans=n;
long long m;
long long zz;
long long a[N],z[N];
//bool bu[N];
queue<int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m%=mod;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//q.push(i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		z[i]=z[i-1]+a[i];
		z[i]%=mod;
		if(a[i-1]!=a[i]){
			q.push(i);
		}
	}
	int l=1,r=1;
	q.pop();
	for(int i=1;i<=n;i++){
		r=i;
		zz=a[i]*(r-l+1)-(z[r]-z[l-1]);
		zz%=mod;
		//cout<<i<<" "<<zz<<endl;
		if(zz>m){
			//cout<<" "<<a[q.front()]-a[l]<<" "<<a[r+1]-a[r]<<endl;
			if(a[q.front()]-a[l]>a[r+1]-a[r]&&r<n){
				l++;
				//cout<<"x "<<l<<" "<<a[q.front()]-a[l]<<" "<<a[r+1]-a[r]<<endl;
				if(a[q.front()]==a[l]){
					//cout<<"pop"<<endl;
					q.pop();
				}
			}else{
				//cout<<":"<<l<<" "<<r<<" "<<endl;
				ans=r-l;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
