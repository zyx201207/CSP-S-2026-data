#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m,mm;
	cin>>n>>m;
	mm=m;
	vector<long long> a(n);
	bool B=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>=2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) B=0;
	}
	if(B){
		int gc=a[1]-a[0];
		long long i=gc,ans=1;
		while(m>=i){
			m-=i;
			i+=gc;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a.begin(),a.end());
	long long ans=1;
	long long curcount=1,curval=a[0];
	long long head=0;
	for(int i=1;i<n;i++){
		m-=(a[i]-curval)*curcount;
		if(m>=0){
			curcount++;
			curval=a[i];
			if(curcount>ans) ans=curcount;
		}
		else{
			while(m<0 && head<i){
				curcount--;
				m+=curval-a[head++];
			}
			if(head==i){
				m=mm;
				curcount=1;
				curval=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
