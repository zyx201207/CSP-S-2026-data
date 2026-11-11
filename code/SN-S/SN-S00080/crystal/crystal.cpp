#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n,mid=(l+r)/2;
	sort(a+1,a+n+1);
	int max_=-1;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	while(l<r){
		int mm=m;
		int sum=0;
		for(int i=mid;i>=1;i--){
			if(mm>=a[mid]-a[i]){
				sum++;
				mm-=a[mid]-a[i];
				cout<<a[i]<<"->"<<a[mid]<<"mm:"<<mm<<"sum:"<<sum<<endl;
//				cout<<mm<<endl;
			}
			else break;
		}
		cout<<"L:"<<l<<" R:"<<r<<"MID:"<<mid<<endl<<sum<<endl;
//		if(sum>max_)l=mid;
//		else{
//			r=mid-1;
//		}
		l++;
		max_=max(max_,sum);
		mid=(l+r)/2;
	}
	cout<<max_;
} 
