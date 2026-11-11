#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long cnt;
int n;
struct no{
	long long k;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	int l=1;
	int r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].k>a[r].k){
				a[l].k-=a[r].k;
				r--;
			}else if(a[l].k==a[r].k){
				l++;
				r--;
			}else if(a[l].k<a[r].k){
				a[r].k-=a[l].k;
				l++;
			}
		}else{
			if(a[l].k>a[r].k){
				cnt+=a[r].k;
				a[l].k-=a[r].k;
				r--;
			}else if(a[l].k==a[r].k){
				cnt+=a[l].k;
				l++;
				r--;
			}else if(a[l].k<a[r].k){
				cnt+=a[l].k;
				a[r].k-=a[l].k;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
