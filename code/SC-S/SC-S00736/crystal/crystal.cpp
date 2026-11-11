#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,n,a[N],sum,ans=0;
bool q=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		long long q=m,cnt=1;
		for(int j=i-1;j>=0;j--){
			q-=a[i]-a[j];
			if(q>0){
				cnt++;
			} 
			else if(q==0){
				cnt++;
				break;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}