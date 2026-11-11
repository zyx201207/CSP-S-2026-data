#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m;
int a[maxn];
int sum[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxi=0;
	for(int i=1;i<=n;i++){
		int lt=i-1,rt=n+1;
		while(lt+1<rt){
			int mid=(lt+rt)>>1;
			if(abs((a[mid]*(mid-i+1))-(sum[mid]-sum[i-1]))<=m) lt=mid;
			else rt=mid;
		}
		if(lt<i){
			lt=i;
		}
		maxi=max(maxi,lt-i+1);
	}
	cout<<maxi;
    return 0;
}
/*
考虑枚举目标值
按照与目标值的差进行排序
答案会有一个最优点 

性质：只能增加不能减少 
*/ 

