#include<bits/stdc++.h>
using namespace std;
struct node{
	int sum,cnt;
};
bool cmp(node x,node y){
	return x.sum<y.sum;
}
bool cmp1(node x,node y){
	return x.cnt>y.cnt;
}
long long int n,m,k,d;
node a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i].sum;
		a[i].cnt = 1;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 2;i<=n;i++){
		if(a[i].sum-m>=a[i-1].sum){
			
			if(a[i].sum-m==a[i-1].sum){
				a[i].cnt = 1;
				break;
				
			}
			else break;
		}
		k = i-1;
		d = m;
		while(k){
			if(d<a[i].sum-a[k].sum){
				break;
			}
			d-=a[i].sum-a[k].sum;
			a[i].cnt++;
			k--;
		}
	}
	sort(a+1,a+n+1,cmp1);
	cout<<a[1].cnt;
	
} 
