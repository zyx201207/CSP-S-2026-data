#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	 cin>>n>>m;
	int a[500005];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	long long s=0;
	int  l=0,ans=0;
	for(int r=0;r<n;r++){
		s+=a[r];
		while((long long)a[r]*(r-l+1)-s>m)
		s-=a[l++];
		int t=r-l+1;
		if(t>ans)ans=t;
	}
	cout<<ans<<endl;
	return 0;
}
