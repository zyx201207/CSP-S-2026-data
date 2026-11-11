#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	int sum=0,ans=1,num=1;//num为当前情况下的最佳答案 
	int l=1,r=2;//双指针扫描  
	int d_l=0;
	long long d_s=0;
	while(r<=n){
		
		d_l=r-l;
		d_s=a[r]-a[r-1];
		if(sum+d_l*d_s>m){//当前情况下不能继续增加 	
			//将左指针右移 
			num--;
			sum-=a[r-1]-a[l];
			l++;
		}
		else{
			sum+=d_l*d_s;
			num++;
			r++;
		}
		ans=max(ans,num);
//		cout<<l<<' '<<r<<" "<<num<<" "<<sum<<"\n";

	}
	cout<<ans;
	return 0;
} 
