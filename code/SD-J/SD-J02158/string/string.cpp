#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
char ch[200005];
int id;
int n;
bool check(long long mid){
	long long cnt=0;
	int i=1,j=n,a1=a[i],a2=a[j];
	while(i<=j){
		if(ch[i]!=ch[j]){
			cnt+=min(a1,a2);
		}
		if(a1>a2){
			j--;
			a1-=a2;
			a2=a[j];
		}else if(a1<a2){
			i++;
			a2-=a1;
			a1=a[i];
		}else{
			i++,j--;
			a2=a[j];
			a1=a[i];
		}
	}
	if(mid>=cnt) return true;
	return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		if(ch[i]!=ch[i-1]&&i!=1) flag=0;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	long long l=0,r=1e15,ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
