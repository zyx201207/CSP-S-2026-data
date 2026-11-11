#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=500005;
int n,m,a[N];
int len;
int l,r;
int flag1,flag2;//flag1:现在花的能量，flag2为每次新的能量
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
	l=1;
	r=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	len++;
	}
	sort(a+1,a+1+n);
	flag1=0;
	while(r<n){
		int mid=r-l+1;
		flag2=a[l]+len*(a[r+1]-a[r]);
		if(flag1<flag2){
			r++;
			flag1=flag2;
		}else{
			if(l<r){
				l++;
				flag1-=(a[l]+a[r]);
				l=r-l+1;
			}
		}
	}
	cout<<a[r];
	return 0;
}

