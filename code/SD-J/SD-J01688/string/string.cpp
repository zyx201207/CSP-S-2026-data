#include<bits/stdc++.h>
using namespace std;
int n,len;
long long ans;
struct node{
	long long num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		len+=a[i].num;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				ans+=a[r].num;
				r--;
			}
			else if(a[l].num==a[r].num){
				ans+=a[r].num;
				a[l].num=0;
				a[r].num=0;
				r--,l++;
			}
			else{
				a[r].num-=a[l].num;
				ans+=a[l].num;
				l++;
			}
		}
		else{
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}
			else if(a[l].num==a[r].num){
				a[l].num=0;
				a[r].num=0;
				r--,l++;
			}
			else{
				a[r].num-=a[l].num;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}   
