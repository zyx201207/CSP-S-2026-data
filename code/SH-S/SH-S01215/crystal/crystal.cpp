#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum;
const int N=5e5;
int a[N];
int n,m;
int q;
int real_ans;
void solve1(int x){
	int b[N]={};
	int ans=0;
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-a[x]);
	}sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(q>=b[i]){
			ans++;
			q-=b[i];
		}else{
			break;
		}
	}real_ans=max(ans,real_ans);
}
void solve2(){
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}int minl=sum,minpoi;;
	for(int i=1;i<=n;i++){
		if(abs(5*a[i]-sum)<=abs(5*minl-sum)){
			minl=a[i];
			minpoi=i;
		}
	}
	solve1(minpoi);
	cout<<real_ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}q=m;
	if(n<=10000){
		for(int i=1;i<=n;i++){
			q=m;
			solve1(i);
		}cout<<real_ans<<endl;
		return 0;
	}else{
		solve2();
	}
	return 0;
}
