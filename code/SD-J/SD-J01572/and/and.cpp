#include<bits/stdc++.h>
using namespace std;
int n,m;
struct p{
	int num,id;
}b[200005];
int a[200005];
int wcnt[35];
bool cmp(p a,p b){
	return a.num>b.num;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].num=a[i];
		b[i].id=i;
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1){
				wcnt[j]++;
			}
		}
	}
	int l=1,r=n;
	for(int i=30;i>=0;i--){
		if(wcnt[i]>=m){
		    long long e=(1<<(i+1))-1;
			for(int j=l;j<=r;j++){
				b[j].num&=e;
			}
			sort(b+l,b+r+1,cmp);
			e=(1<<i);
			for(int j=l;j<=r;j++){
				if(!(b[j].num&e)){
					r=j-1;
					break;
				}
			}
		}
	}
	long long summ=(1<<31)-1;
	for(int i=1;i<=m;i++){
		summ&=a[b[i].id];
	}
	cout<<summ;
	return 0;
} 
//and5.ans and.out
