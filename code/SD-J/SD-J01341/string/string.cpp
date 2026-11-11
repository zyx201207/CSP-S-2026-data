#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Node{
	int num;
	char w;
}a[200005];
int n;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].w;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].w==a[r].w){
			if(a[l].num>=a[r].num){
				a[l].num=(a[l].num-a[r].num);
				r--;
			}
			else{
				a[r].num=(a[r].num-a[l].num);
				l++;
			} 
		}
		else{
			if(a[l].num>=a[r].num){
				a[l].num=(a[l].num-a[r].num);
				cnt+=a[r].num;
				r--;
			}
			else{
				a[r].num=(a[r].num-a[l].num);
				cnt+=a[l].num;
				l++;
			} 
		}
	}
	cout<<cnt;
	return 0;
} 
