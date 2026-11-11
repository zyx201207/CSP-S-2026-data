#include<bits/stdc++.h>
using namespace std;
long long k;
int n;
long long a[500010];
long long b[500010];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==1) b[i]=0;
		if(i!=1) b[i]=a[i]-a[i-1];
	}
//	for(int i=1;i<=n;i++){
//		b[i]=b[i]*(i-1);
////		cout<<b[i]<<' ';
//	}
	long long sum=0;int da=1;
	int h=1,t=1;
	for(int i=2;i<=n;i++){
		if(sum<=k){
			da=max(da,(t-h+1));
		}sum=sum+(b[i]*(t-h+1));
		t++;
//		cout<<da<<' '<<sum<<' '<<h<<' '<<t<<' '<<i<<'\n';
//		cout<<da<<' '<<sum<<'\n';
		if(sum>=k){
			while(sum>k&&h<t){
				sum-=(a[i]-a[h]);
				h++; 
			}
		}
		
		if(sum<=k){
			da=max(da,(t-h+1));
		}
		
	}
	cout<<da;
	return 0;
} 

/*
我吹过你曾吹过的晚风，那我算不算和你相拥 
*/
/*
该怎么去形容你最贴切
拿什么和你做比较才算特别
对你的感觉强烈
却又不太了解
全凭直觉
你是窝在被子里的舒服
却又像风琢磨不住
像手腕散发的香水味
还想爱不释手的红色高跟鞋
*/
 /*RP++*/ 
