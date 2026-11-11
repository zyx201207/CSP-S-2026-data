#include<bits/stdc++.h>
using namespace std;
const int N=10e5+10;
long long n,m,cnt,ans,num,MAX;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int x=a[0];x<=a[n-1]+m;x++){
	for(int i=0;i<n;i++){
		if(a[i]<MAX){
			cnt+=MAX-a[i]+1;
			a[i]=MAX;
			if(cnt==m-1) break;
		}
	}
	if(cnt>=m) MAX--;
	else MAX++;
	num=0;
	for(int j=0;j<n;j++){
		for(int z=j;z<n;z++){
			if(a[j]==a[z] && j!=z) num++;
		}
	}
	ans=max(ans,num);
	}
	cout<<ans<<endl;
	return 0;
}	
