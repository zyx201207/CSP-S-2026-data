#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,sum=0;
	pair<int,char> a[200005]; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	} 
	for(int i=1,j=n;i<=j;i++){
		for(;a[i].first>0;j--){
			if(a[i].second==a[j].second){
				if(a[i].first>a[j].first){
					a[i].first-=a[j].first;
					a[j].first=0;
				}else{
					a[j].first-=a[i].first;
					a[i].first=0;
				}
			}else{
				if(a[i].first>a[j].first){
					sum+=a[j].first;
					a[i].first-=a[j].first;
					a[j].first=0;
				}else{
					sum+=a[i].first;
					a[j].first-=a[i].first;
					a[i].first=0;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
