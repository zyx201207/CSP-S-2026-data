#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}a[200005];
long long l=1,r,cnt=0;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	r=n;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}
			else {
				l++;
				r--;
			}
		}
		else if(a[l].c!=a[r].c){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				cnt+=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				cnt+=a[l].num;
				l++;
			}
			else {
				cnt+=a[r].num;
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
