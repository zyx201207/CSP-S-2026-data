#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long num;
	char ch;
}a[500000];
long long slove(int n){
	long long cnt=0;
	int l=1,r=n;
	while(l<=r){
		if(l==r){
			if(a[l].num%2==1) return cnt;
			else return cnt+1;
		}
		if(a[l].ch==a[r].ch){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l].num>a[r].num){
				cnt+=a[r].num;
				a[l].num-=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				cnt+=a[l].num;
				a[r].num-=a[l].num;
				l++;
			}
			else{
				cnt+=a[l].num;
				l++;
				r--;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].ch;
	cout<<slove(n);
	return 0;
}