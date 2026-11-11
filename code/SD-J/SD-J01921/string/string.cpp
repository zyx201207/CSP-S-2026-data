#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long cnt;
struct node{
	long long sum;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].sum<a[r].sum){
				a[r].sum-=a[l].sum;
				l++;
			}
			else if(a[l].sum>a[r].sum){
				a[l].sum-=a[r].sum;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l].sum<a[r].sum){
				a[r].sum-=a[l].sum;
				cnt+=a[l].sum;
				l++;
			}
			else if(a[l].sum>a[r].sum){
				a[l].sum-=a[r].sum;
				cnt+=a[r].sum;
				r--;
			}
			else{
				cnt+=a[l].sum;
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
}
//mugun+mugun=mugunmugun=mugun
//so mugun=0=zjc
