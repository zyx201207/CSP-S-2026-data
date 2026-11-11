#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[500010],ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		t[a[i]]++;
	}
	sort(a+1,a+1+n);
	int cry=0;
	for(int i=n;i>=1;i--){
		cry=ans+m;
		if(cry%i==0&&a[i]<=cry/i){
			cnt=i;
			break;
		}
		else{
			ans-=a[i];
		}
	}
	cout<<cnt;
	return 0;
} 
