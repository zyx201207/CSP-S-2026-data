#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+5;
pair<long long,char> a[mn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		cin>>a[i].second;
	}
	long long cnt=0;
	while(l<r){
//		cout<<"123452";
		if(a[l].second==a[r].second){
			if(a[l].first<a[r].first){
				a[r].first-=a[l].first;
				l++;
			}else{
				a[l].first-=a[r].first;
				if(a[l].first==0){
					l++;
				}
				r--;
			}
		}else{
			if(a[l].first<a[r].first){
				cnt+=a[l].first;
				a[r].first-=a[l].first;
				l++;
			}else{
				cnt+=a[r].first;
				a[l].first-=a[r].first;
				if(a[l].first==0){
					l++;
				}
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
