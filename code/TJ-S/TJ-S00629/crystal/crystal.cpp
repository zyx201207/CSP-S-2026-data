#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500005];
long long int cha[500005];
int cnt2;
int cnp;
int main(){//贪心 求最大 列举出最常见两种情况 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=0;
	int r=n;
	int mid=(l+r)/2;
	int m2=m;
	int cnt=1;//算自己 
	for(int i=mid;i>=1;i--){
		m2-=mid-a[i];
		cnt++;
		if(m2<0){
			cnt--;
			break;
		}
		if(m2==0){
			break;
		}
	}//仅仅针对于以中间数字为基准的情况 
	long long int maxn1=-1e19;
	int c=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			c++;
		}
		else{
			if(c>maxn1){
				maxn1=c;	
				cnp=i;
			} 
			c=0;
		}
	}
	for(int i=cnp;i>=1;i--){
		m-=a[cnp]-a[i];
		cnt2++;
		if(m<0){
			cnt2--;
			break;
		}
		if(m==0){
			break;
		}
	}//仅仅针对于以出现次数最多的数为基准的情况 
	if(cnt>=cnt2){
		cout<<cnt;
		return 0;
	}//总汇总 两种情况哪个大输出哪个 
	cout<<cnt2; 
	return 0;
}
