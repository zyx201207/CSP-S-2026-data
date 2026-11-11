#include<bits/stdc++.h>
using namespace std;
int n,ans,mm,num=1,a[100005];
int minx;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a,a+n);
	for(int mid=2;mid<=n;mid++){
		for(int i=mid-1;mm>0&&i>0;i--)
			mm-=(a[mid]-a[i])/*d[i]*/,num++;
		if(mm<0){
			num--;
		}
		ans=max(num,ans),mm=m,num=1;	
	}
	cout<<ans;
	return 0;
}

