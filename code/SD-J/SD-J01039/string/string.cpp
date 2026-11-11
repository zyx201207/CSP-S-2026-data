#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n;
long long num[N],ans=0;
char a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}	
	int l=1,r=n;
	while(l<r){
		if(num[l]>num[r]){
			num[l]-=num[r];
			if(a[l]!=a[r]){
				ans+=num[r];
			}
			r--;
		}
		if(num[l]==num[r]){
			if(a[l]!=a[r]){
				ans+=num[l];
			}
			l++;
			r--;	
		}
		if(num[l]<num[r]){
			num[r]-=num[l];
			if(a[l]!=a[r]){
				ans+=num[l];
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
