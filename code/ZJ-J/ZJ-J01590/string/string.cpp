#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int num;
	char c;
};
node a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].num<a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
			a[r].num-=a[l].num;
			l++;
		}else if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[r].num;
			}
			a[l].num-=a[r].num;
			r--;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
