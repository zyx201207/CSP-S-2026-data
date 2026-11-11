#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
struct p{
	ll nu;
	char c;
}a[200008];
int main () {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ll n,sum=0;
	cin >> n;
	ll mid=(n+1)/2;
	for(int i=0;i<n;i++){
		cin >> a[i].nu >> a[i].c;
	}
	int j=0;
	for(int i=0;i<=mid;i++){
			if(a[mid+i].nu==a[mid-j].nu){
				if(a[mid+i].c!=a[mid-j].c){
					sum+=a[mid+i].nu;
				}
			}
			else{
				if(a[mid+i].nu>a[mid-j].nu){
					i--;
					if(a[mid+i].c==a[mid-j].c){
						a[mid+i].nu-=a[mid-j].nu;
						sum+=a[mid-j].nu;
					}
				}
				else{
					j--;
					if(a[mid-j].c==a[mid+i].c){
						a[mid-j].nu-=a[mid+i].nu;
						sum+=a[mid+i].nu;
					}
				}
			}
		j++;
	}
	cout << sum;
	return 0;
}
