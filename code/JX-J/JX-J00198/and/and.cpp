#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,max1=-1;
long long a[N];
bool t[N];
int shu(long long n,int j){
	int cnt=0;
	for(int i=1;i<=j;i++){
		while(n){
			if(n%2==1)cnt++;
			n/=2;
		}
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ans=a[1];
	int i1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int max2=shu(a[i],i);
		if(max1<=max2){
			max1=max2;
			i1=i;
			ans=a[i1];
			t[i1]=1;
		}
	}
	//cout<<a[i1]<<' '<<t[a[i1]]<<endl;
	for(int i=1;i<m;i++){
		max1=-1,i1=0;
		for(int j=1;j<=n;j++){
			int max2=shu(a[j],j);
			//cout<<t[j]<<endl;
			if(max1<=max2){
				if(t[j]==1)continue;
				max1=max2;
				i1=j;
				//cout<<j<<' '<<a[j]<<endl;
			}
		}
		ans=ans&a[i1];
	}
	cout<<ans;
	return 0;
}
