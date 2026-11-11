#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long LL;
LL sum = 0,ans;
struct Node{
	LL chang;
	char op;
};Node a[N];
Node q[N];
Node l[N];
LL m = 1,zs;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	for(LL i = 1;i <= n;i++) cin>>a[i].chang>>a[i].op,sum+=a[i].chang;
	if(sum%2 != 0){
		sum/=2,sum++;
		while(a[m].chang <= sum){
	        sum-=a[m].chang,m++;
	    }
	    zs = a[m].chang - sum;
	    a[m].chang = sum - 1;
	}else if(sum%2 == 0){
		sum/=2;
		while(a[m].chang <= sum){
			sum-=a[m].chang,m++;
		}
		zs = a[m].chang - sum;
		a[m].chang = sum;
	}
	LL P = (a[m].chang == 0 ? m-1 : m);
	LL Q = n - m;
	for(LL i = 1;i <= P;i++) {
	    q[i].chang = a[i].chang,q[i].op = a[i].op;
	}
	for(LL i = 1;i <= Q;i++){
	    l[i].chang = a[n-i+1].chang,l[i].op = a[n-i+1].op;
	}
	Q++;
	l[n-m+1].chang = zs,l[n-m+1].op = a[m].op;
	LL j = 1,i = 1;
	while(i <= P&&j <= Q){
		if(q[i].chang > l[j].chang){
			if(q[i].op != l[j].op){
				ans+=l[j].chang;
				q[i].chang-=l[j].chang;
				j++;
			}else{
				q[i].chang-=l[j].chang;
				j++;
			}
		}else if(q[i].chang < l[j].chang){
			if(q[i].op != l[j].op){
				ans+=q[i].chang;
				l[j].chang-=q[i].chang;
				i++;
			}else{
				l[j].chang-=q[i].chang;
				i++;
			}
		}else if(q[i].chang == l[j].chang){
			if(q[i].op != l[j].op){
				ans+=q[i].chang;
				l[j].chang = 0;
				q[i].chang = 0;
				j++;
				i++;
			}else{
				l[j].chang = 0;
				q[i].chang = 0;
				j++;
				i++;
			}
		}
	}
	ans+=q[P].chang;
	ans+=l[Q].chang;
	cout<<ans;
	return 0;
}
