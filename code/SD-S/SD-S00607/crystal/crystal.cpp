#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],pre[500005],dif[500005],tmp,maxn; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		dif[i]=a[i]-a[i-1];
	}
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				tmp=(j-i)*a[j]-pre[j-1]+pre[i-1];
//				for(int k=i;k<j;k++) tmp+=(a[j]-a[k]);
				if(tmp>m) break;
				else maxn=max(maxn,j-i+1);
			}
		}
		cout<<maxn;
	} 
	else{
		int d=dif[2];
		for(long long i=1;i<=n;i++){
			if(((i*(i-1))>>1)*d<=m) maxn=max(maxn,i);
			else break;
		}
		cout<<maxn;
	}
	return 0;
}
//wuchuangtianjia
/*
fc crystal1.ans crystal1.out /n
fc crystal2.ans crystal2.out /n
fc crystal3.ans crystal3.out /n
fc crystal4.ans crystal4.out /n
fc crystal5.ans crystal5.out /n 
*/
/*
rank
14:30:00 000+000+000+000
15:39:39 045+000+000+000
16:03:56 075+000+000+000
Finally? 
Finally. 
18:15:51 075+000+000+000
18:30:00 075+000+000+000
*/
