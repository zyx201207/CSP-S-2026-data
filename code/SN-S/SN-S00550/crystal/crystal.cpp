#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	long long n=0;
	long long ans=1;
	long long total=0;
	cin>>n>>m;
	long long a[n+5];
	long long cnt[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		total+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
		return 0;
	}
	long long most=total/n;
	long long pos=lower_bound(a+1,a+n+1,most)-a;
	long long pos1=pos+1;
	long long keyy=a[pos];
	while(a[pos1]==keyy){
		pos=pos1;
		pos1++;
	}
	if(m==0){
		ans--;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		ans=cnt[1];
		for(int i=1;i<=n;i++){
			if(ans<cnt[i]){
				ans=cnt[i];
			}
		}
		cout<<ans;
		return 0;
	}
	pos--;
	while(pos!=0){
		long long divide=keyy-a[pos];
		pos--;
		if((m-divide)>=0){
		m-=divide;
		ans++;	
		}else{
			break;
		}
	}
	while(m>=0 and pos1<=n){
		long long price=(a[pos1]-a[pos1-1])*(pos1-1);
		if((m-price)>=0){
		m-=price;
		ans++;
		pos1++;	
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
