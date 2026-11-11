#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
	}
	int ans=0,sum=0;
	for(int i=1;i<n;i++){
		if(m-b[i]>0){
			m-=b[i];
			ans++;
			sum++;
			if(sum==2){
				ans++;
				sum=0;
			}
		}else{
			break;
		}
	}
	cout<<ans;
	//2 4 6 8 10 1 2 3 4 5  
	return 0;
}
