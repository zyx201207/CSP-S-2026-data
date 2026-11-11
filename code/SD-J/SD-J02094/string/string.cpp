#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
const int N = 1e6+10; 
struct node{
	int num;
	char c;
}a[N];
int n;
ll cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	int l=1,r=n;
	while(l<=r){
		if(a[l].num==a[r].num){
			if(a[l].c==a[r].c) l++,r--;
			else cnt+=a[l].num,l++,r--;
		}
		else{
			if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				if(a[l].c==a[r].c) l++;
				else cnt+=a[l].num,l++;
			}
			else{
				a[l].num-=a[r].num;
				if(a[l].c==a[r].c) r--;
				else cnt+=a[r].num,r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

